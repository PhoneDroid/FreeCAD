﻿/***************************************************************************
 *   Copyright (c) 2012-2013 Luke Parry <l.parry@warwick.ac.uk>            *
 *   Copyright (c) 2024 Benjamin Bræstrup Sayoc <benj5378@outlook.com>     *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#include "PreCompiled.h"
#ifndef _PreComp_
# include <QApplication>
# include <QGraphicsSceneHoverEvent>
# include <QGraphicsSceneMouseEvent>
# include <QPainter>
# include <QStyleOptionGraphicsItem>
# include <QTransform>
#endif

#include <App/Application.h>
#include <App/DocumentObject.h>
#include <Base/Console.h>
#include <Base/Tools.h>
#include <Gui/Application.h>
#include <Gui/Document.h>
#include <Gui/MainWindow.h>
#include <Gui/Selection/Selection.h>
#include <Gui/Tools.h>
#include <Gui/ViewProvider.h>
#include <Mod/TechDraw/App/DrawPage.h>
#include <Mod/TechDraw/App/DrawProjGroup.h>
#include <Mod/TechDraw/App/DrawProjGroupItem.h>
#include <Mod/TechDraw/App/DrawViewSection.h>
#include <Mod/TechDraw/App/DrawViewPart.h>
#include <Mod/TechDraw/App/DrawUtil.h>
#include <Mod/TechDraw/App/DrawView.h>

#include "QGIView.h"
#include "MDIViewPage.h"
#include "PreferencesGui.h"
#include "QGCustomBorder.h"
#include "QGCustomClip.h"
#include "QGCustomImage.h"
#include "QGCustomLabel.h"
#include "QGICaption.h"
#include "QGIEdge.h"
#include "QGIVertex.h"
#include "QGIViewClip.h"
#include "QGIUserTypes.h"
#include "QGSPage.h"
#include "QGVPage.h"
#include "Rez.h"
#include "ViewProviderDrawingView.h"
#include "ViewProviderPage.h"
#include "ZVALUE.h"
#include "DrawGuiUtil.h"


using namespace TechDrawGui;
using namespace TechDraw;
using DU = DrawUtil;

const float labelCaptionFudge = 0.2f;   // temp fiddle for devel

QGIView::QGIView()
    :QGraphicsItemGroup(),
    viewObj(nullptr),
    m_innerView(false),
    m_multiselectActivated(false),
    snapping(false)
{
    setCacheMode(QGraphicsItem::NoCache);
    setHandlesChildEvents(false);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    m_colNormal = prefNormalColor();
    m_colCurrent = m_colNormal;
    m_pen.setColor(m_colCurrent);

    m_decorPen.setStyle(Qt::DashLine);
    m_decorPen.setWidth(0); // 0 => 1px "cosmetic pen"

    m_label = new QGCustomLabel();
    addToGroup(m_label);
    m_border = new QGCustomBorder();
    addToGroup(m_border);
    m_caption = new QGICaption();
    addToGroup(m_caption);
    m_lock = new QGCustomImage();
    m_lock->setParentItem(m_border);
    m_lock->load(QStringLiteral(":/icons/TechDraw_Lock.svg"));
    QSize sizeLock = m_lock->imageSize();
    m_lockWidth = (double) sizeLock.width();
    m_lockHeight = (double) sizeLock.height();
    m_lock->hide();
}

void QGIView::isVisible(bool state)
{
    auto feat = getViewObject();
    if (!feat) return;
    auto vp = QGIView::getViewProvider(feat);
    if (!vp) return;
    Gui::ViewProviderDocumentObject* vpdo = dynamic_cast<Gui::ViewProviderDocumentObject*>(vp);
    if (!vpdo) return;
    vpdo->Visibility.setValue(state);
}

bool QGIView::isVisible()
{
    auto feat = getViewObject();
    if (!feat) return false;
    auto vp = QGIView::getViewProvider(feat);
    if (!vp) return false;
    Gui::ViewProviderDocumentObject* vpdo = dynamic_cast<Gui::ViewProviderDocumentObject*>(vp);
    if (!vpdo) return false;
    return vpdo->Visibility.getValue();
}

//Gets selection state for this view and/or eventually its children
bool QGIView::getGroupSelection()
{
    return isSelected();
}

//Set selection state for this and its children
//required for items like dimensions & balloons
void QGIView::setGroupSelection(bool isSelected)
{
    setSelected(isSelected);
}

// Set selection state of the feature (empty subName) or its sub items
void QGIView::setGroupSelection(bool isSelected, const std::vector<std::string> &subNames)
{
    Q_UNUSED(subNames);
    setGroupSelection(isSelected);
}

void QGIView::alignTo(QGraphicsItem*item, const QString &alignment)
{
    alignHash.clear();
    alignHash.insert(alignment, item);
}

QVariant QGIView::itemChange(GraphicsItemChange change, const QVariant &value)
{
    //    Base::Console().message("QGIV::itemChange(%d)\n", change);
    if(change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();            //position within parent!

        TechDraw::DrawView *viewObj = getViewObject();
        auto* dpgi = dynamic_cast<TechDraw::DrawProjGroupItem*>(viewObj);
        if (dpgi && dpgi->getPGroup()) {
            // restrict movements of secondary views.
            if(alignHash.size() == 1) {   //if aligned.
                QGraphicsItem* item = alignHash.begin().value();
                QString alignMode   = alignHash.begin().key();
                if(alignMode == QStringLiteral("Vertical")) {
                    newPos.setX(item->pos().x());
                }
                else if(alignMode == QStringLiteral("Horizontal")) {
                    newPos.setY(item->pos().y());
                }
            }
        }
        else {
            // For general views we check if we need to snap to a position
            if (!(QApplication::keyboardModifiers() & Qt::AltModifier)) {
                snapPosition(newPos);
            }
        }

                // tell the feature that we have moved
        Gui::ViewProvider *vp = getViewProvider(viewObj);
        if (vp && !vp->isRestoring()) {
            snapping = true; // avoid triggering updateView by the VP updateData
            viewObj->setPosition(Rez::appX(newPos.x()), Rez::appX(-newPos.y()));
            snapping = false;
        }

        return newPos;
    }

    if (change == ItemSelectedHasChanged && scene()) {
        if(isSelected()) {
            m_colCurrent = getSelectColor();
        } else {
            m_colCurrent = PreferencesGui::getAccessibleQColor(PreferencesGui::normalQColor());
        }
        drawBorder();
    }

    return QGraphicsItemGroup::itemChange(change, value);
}

//! align this view with others.  newPosition is in this view's parent's coord
//! system.  if this view is not in a ProjectionGroup, then this is the scene
//! position, otherwise it is the position within the ProjectionGroup.
void QGIView::snapPosition(QPointF& newPosition)
{
    if (!Preferences::SnapViews()) {
        return;
    }

    auto feature = getViewObject();
    if (!feature) {
        return;
    }

    auto dvp = freecad_cast<DrawViewPart*>(feature);
    if (dvp  &&
        !dvp->hasGeometry()) {
        // too early. wait for updates to finish.
        return;
    }

    auto vpPage = getViewProviderPage(feature);

    QGSPage* scenePage = vpPage->getQGSPage();
    if (!scenePage) {
        return;
    }

    auto* sectionView = dynamic_cast<TechDraw::DrawViewSection*>(feature);
    if (sectionView) {
        snapSectionView(sectionView, newPosition);
        return;
    }

    // For general views we check if the view is close to aligned vertically or horizontally to another view.

    // if we are not a section view, then we could be in a projection group and
    // need to get the correct scene position.
    auto newScenePos = newPosition;
    if (parentItem()) {
        newScenePos = parentItem()->mapToScene(newPosition);
    }

    // First get a list of the views of the page.
    qreal snapPercent = Preferences::SnapLimitFactor();
    std::vector<QGIView*> views = scenePage->getViews();
    for (auto* view : views) {
        if (view == this) {
            continue;
        }
        auto viewFeature = view->getViewObject();
        auto viewDvp = freecad_cast<DrawViewPart*>(viewFeature);

        auto viewScenePos = view->scenePos();
        if (viewDvp &&
            DrawView::isProjGroupItem(viewDvp)) {
            viewScenePos = DU::toQPointF(projItemPagePos(viewDvp));
            viewScenePos = DU::invertY(Rez::guiX(viewScenePos));
        }

        auto xwindow = view->boundingRect().width() * snapPercent;
        auto ywindow = view->boundingRect().height() * snapPercent;

        auto xerror = fabs(newScenePos.x() - viewScenePos.x());
        auto yerror = fabs(newScenePos.y() - viewScenePos.y());

                // if the smaller of vertical and horizontal errors is within the acceptable
                // window, snap to position.
        if (xerror <= yerror  &&
            xerror <= xwindow) {
            newScenePos.setX(viewScenePos.x());
            if (parentItem()) {
                newScenePos = parentItem()->mapFromScene(newScenePos);
            }
            newPosition = newScenePos;
            return;
        }

        if (yerror < xerror &&
            yerror <= ywindow) {
            newScenePos.setY(viewScenePos.y());
            if (parentItem()) {
                newScenePos = parentItem()->mapFromScene(newScenePos);
            }
            newPosition = newScenePos;
            return;
        }
    }
}


//! snap this section view to its base view.  The section should be positioned on
//! line from the base view along the section normal direction, ie the same direction
//! as the arrows on the section line.
// Note: positions are in Qt inverted Y coordinates. They need to be converted before
// doing math on them, then converted back on return.
// Note: section views are never inside a ProjectionGroup, so their position is
// always in scene coordinates.
void QGIView::snapSectionView(const TechDraw::DrawViewSection* sectionView,
                              QPointF& newPosition)
{
    auto* baseView = sectionView->getBaseDVP();
    if (!baseView) {
        return;
    }
    auto* vpdv = freecad_cast<ViewProviderDrawingView*>(getViewProvider(baseView));
    if (!vpdv) {
        return;
    }
    auto* qgiv(dynamic_cast<QGIView*>(vpdv->getQView()));
    if (!qgiv) {
        return;
    }

    Base::Vector3d arrowDirection = sectionView->SectionNormal.getValue() * -1;
    auto arrowDirectionOnBase = baseView->projectPoint(arrowDirection, false);
    if (arrowDirectionOnBase.Length() < Precision::Confusion()) {
        return;
    }
    arrowDirectionOnBase.Normalize();
    double baseSize = Rez::guiX(baseView->getSizeAlongVector(arrowDirectionOnBase));
    double snapDist = baseSize * getScale() * Preferences::SnapLimitFactor();

    // find the scene position of the SO on the base view
    auto baseX = baseView->X.getValue();
    auto baseY = baseView->Y.getValue();
    Base::Vector3d baseScenePos{baseX, baseY, 0};       // paper space position
    if (DrawView::isProjGroupItem(baseView)) {
        baseScenePos = projItemPagePos(baseView);
    }
    auto sectionOrg3d      = sectionView->SectionOrigin.getValue();
    auto shapeCenter3d     = baseView->getCurrentCentroid();
    auto baseShapeCenter   = baseView->projectPoint(shapeCenter3d, false);
    auto baseSectionOrg    = baseView->projectPoint(sectionOrg3d, false);
    auto baseSOOffset      = (baseSectionOrg - baseShapeCenter) * baseView->getScale();
    auto baseSOScenePos    = baseScenePos + baseSOOffset;

    // find the SO offset from origin on the rotated & scaled sectionView
    auto sectionCutCenter     = sectionView->projectPoint(sectionView->getCutCentroid(), false);
    auto sectionSectionOrg    = sectionView->projectPoint(sectionOrg3d, false);
    auto sectionSOOffset      = (sectionSectionOrg - sectionCutCenter) * sectionView->getScale();
    auto sectionRotationDeg = sectionView->Rotation.getValue();
    sectionSOOffset.RotateZ(Base::toRadians(sectionRotationDeg));

            // from here on, we work with scene units (1/10 mm)
    sectionSOOffset = Rez::guiX(sectionSOOffset);
    baseSOScenePos  = Rez::guiX(baseSOScenePos);

            // check our alignment
    auto newSOPosition = DU::invertY(DU::toVector3d(newPosition)) + sectionSOOffset;

    Base::Vector3d actualAlignmentVector = newSOPosition - baseSOScenePos;
    actualAlignmentVector.Normalize();

    // if we are not on the correct side of the section line, we should not try to snap
    auto dot = arrowDirectionOnBase.Dot(actualAlignmentVector);
    if (dot <= 0) {
        return;
    }

    auto pointOnArrowLine = newSOPosition.Perpendicular(baseSOScenePos, arrowDirectionOnBase);
    auto errorVector = pointOnArrowLine - newSOPosition;
    if (errorVector.Length() < snapDist) {
        // get the position point corresponding to our SO alignment
        auto netPosition = pointOnArrowLine - sectionSOOffset;
        netPosition = DU::invertY(netPosition);
        newPosition = DU::toQPointF(netPosition);
    }

    return;
}

Base::Vector3d  QGIView::projItemPagePos(DrawViewPart* item)
{
    if (!DrawView::isProjGroupItem(item)) {
        return Base::Vector3d(0, 0, 0);
    }
    auto dpgi = static_cast<DrawProjGroupItem*>(item);
    auto group = dpgi->getPGroup();

    auto itemX = dpgi->X.getValue();
    auto itemY = dpgi->Y.getValue();
    Base::Vector3d itemOffsetPos{itemX, itemY, 0};       // relative to group
    auto groupX = group->X.getValue();
    auto groupY = group->Y.getValue();
    Base::Vector3d groupPagePos{groupX, groupY, 0};    // relative to page
    return groupPagePos + itemOffsetPos;
}


void QGIView::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    // this is never called for balloons (and dimensions?) because the label objects do not
    // inherit from QGIView, but directly from QGraphicsItem. - wf

    Qt::KeyboardModifiers originalModifiers = event->modifiers();
    if (event->button()&Qt::LeftButton) {
        m_multiselectActivated = false;
    }

    if (event->button() == Qt::LeftButton && PreferencesGui::multiSelection()) {
        std::vector<Gui::SelectionObject> selection = Gui::Selection().getSelectionEx();
        if (!DrawGuiUtil::getSubsForSelectedObject(selection, getViewObject()).empty()) {
            // we have already selected geometry for this view
            m_multiselectActivated = true;
            event->setModifiers(originalModifiers | Qt::ControlModifier);
        }
    }

    QGraphicsItemGroup::mousePressEvent(event);

    event->setModifiers(originalModifiers);
}

void QGIView::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    QGraphicsItemGroup::mouseMoveEvent(event);
}

void QGIView::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    Qt::KeyboardModifiers originalModifiers = event->modifiers();
    if ((event->button()&Qt::LeftButton) && m_multiselectActivated) {
        if (PreferencesGui::multiSelection()) {
            event->setModifiers(originalModifiers | Qt::ControlModifier);
        }

        m_multiselectActivated = false;
    }

    QGraphicsItemGroup::mouseReleaseEvent(event);

    event->setModifiers(originalModifiers);
}

void QGIView::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //    Base::Console().message("QGIV::hoverEnterEvent()\n");
    Q_UNUSED(event);
    // TODO don't like this but only solution at the minute (MLP)
    if (isSelected()) {
        m_colCurrent = getSelectColor();
        setFocus();
    } else {
        m_colCurrent = getPreColor();
    }
    drawBorder();
}

void QGIView::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    if(isSelected()) {
        m_colCurrent = getSelectColor();
    } else {
        m_colCurrent = PreferencesGui::getAccessibleQColor(PreferencesGui::normalQColor());
    }
    drawBorder();
}

//sets position in /Gui(graphics), not /App
void QGIView::setPosition(qreal xPos, qreal yPos)
{
    //    Base::Console().message("QGIV::setPosition(%.3f, %.3f) (gui)\n", x, y);
    double newX = xPos;
    double newY = -yPos;
    double oldX = pos().x();
    double oldY = pos().y();

    if (TechDraw::DrawUtil::fpCompare(newX, oldX) &&
        TechDraw::DrawUtil::fpCompare(newY, oldY)) {
        return;
    } else {
        setPos(newX, newY);
    }
}

QGIViewClip* QGIView::getClipGroup()
{
    if (!getViewObject()->isInClip()) {
        return nullptr;
    }

    auto parentClip( dynamic_cast<QGCustomClip*>( parentItem() ) );
    if (!parentClip) return nullptr;

    auto parentView( dynamic_cast<QGIViewClip*>( parentClip->parentItem() ) );
    return parentView;
}

void QGIView::updateView(bool forceUpdate)
{
    //    Base::Console().message("QGIV::updateView() - %s\n", getViewObject()->getNameInDocument());

            //allow/prevent dragging
    if (getViewObject()->isLocked()) {
        setFlag(QGraphicsItem::ItemIsMovable, false);
    } else {
        setFlag(QGraphicsItem::ItemIsMovable, true);
    }

    if (getViewObject() && forceUpdate) {
        setPosition(Rez::guiX(getViewObject()->X.getValue()),
                    Rez::guiX(getViewObject()->Y.getValue()));
    }

    double appRotation = getViewObject()->Rotation.getValue();
    double guiRotation = rotation();
    if (!TechDraw::DrawUtil::fpCompare(appRotation, guiRotation)) {
        rotateView();
    }

    QGIView::draw();
}

//QGIVP derived classes do not need a rotate view method as rotation is handled on App side.
void QGIView::rotateView()
{
    //NOTE: QPainterPaths have to be rotated individually. This transform handles Rotation for everything else.
    //Scale is handled in GeometryObject for DVP & descendents
    //Objects not descended from DVP must setScale for themselves
    //note that setTransform(, ,rotation, ,) is not the same as setRotation!!!
    double rot = getViewObject()->Rotation.getValue();
    QPointF centre = boundingRect().center();
    setTransform(QTransform().translate(centre.x(), centre.y()).rotate(-rot).translate(-centre.x(), -centre.y()));
}

double QGIView::getScale()
{
    TechDraw::DrawView* feat = getViewObject();
    if (!feat) {
        return 1.0;
    }
    return feat->getScale();
}
const char * QGIView::getViewName() const
{
    return viewName.c_str();
}
const std::string QGIView::getViewNameAsString() const
{
    return viewName;
}


TechDraw::DrawView * QGIView::getViewObject() const
{
    return viewObj;
}

void QGIView::setViewFeature(TechDraw::DrawView *obj)
{
    if (!obj)
        return;

    viewObj = obj;
    viewName = obj->getNameInDocument();

            //mark the actual QGraphicsItem so we can check what's in the scene later
    setData(0, QStringLiteral("QGIV"));
    setData(1, QString::fromUtf8(obj->getNameInDocument()));
}

void QGIView::toggleCache(bool state)
{
    // temp for devl. chaching was hiding problems WF
    //setCacheMode((state)? NoCache : NoCache);
    Q_UNUSED(state);
    setCacheMode(NoCache);
}

void QGIView::draw()
{
    //    Base::Console().message("QGIV::draw()\n");
    double xFeat, yFeat;
    if (getViewObject()) {
        xFeat = Rez::guiX(getViewObject()->X.getValue());
        yFeat = Rez::guiX(getViewObject()->Y.getValue());
        if (!getViewObject()->LockPosition.getValue()) {
            setPosition(xFeat, yFeat);
        }
    }
    if (isVisible()) {
        drawBorder();
        show();
    } else {
        hide();
    }
}

void QGIView::drawCaption()
{
    //    Base::Console().message("QGIV::drawCaption()\n");
    prepareGeometryChange();
    QRectF displayArea = customChildrenBoundingRect();
    m_caption->setDefaultTextColor(m_colCurrent);
    m_font.setFamily(Preferences::labelFontQString());
    int fontSize = exactFontSize(Preferences::labelFont(),
                                 Preferences::labelFontSizeMM());
    m_font.setPixelSize(fontSize);
    m_caption->setFont(m_font);
    QString captionStr = QString::fromUtf8(getViewObject()->Caption.getValue());
    m_caption->setPlainText(captionStr);
    QRectF captionArea = m_caption->boundingRect();
    QPointF displayCenter = displayArea.center();
    m_caption->setX(displayCenter.x() - captionArea.width()/2.);
    double labelHeight = (1 - labelCaptionFudge) * m_label->boundingRect().height();
    auto vp = static_cast<ViewProviderDrawingView*>(getViewProvider(getViewObject()));
    if (getFrameState() || vp->KeepLabel.getValue()) {            //place below label if label visible
        m_caption->setY(displayArea.bottom() + labelHeight);
    } else {
        m_caption->setY(displayArea.bottom() + labelCaptionFudge * Preferences::labelFontSizeMM());
    }
    m_caption->show();
}

void QGIView::drawBorder()
{
    //    Base::Console().message("QGIV::drawBorder() - %s\n", getViewName());
    auto feat = getViewObject();
    if (!feat)
        return;

    drawCaption();   //always draw caption

    auto vp = static_cast<ViewProviderDrawingView*>(getViewProvider(getViewObject()));
    if (!getFrameState() && !vp->KeepLabel.getValue()) {
        m_label->hide();
        m_border->hide();
        m_lock->hide();
        return;
    }

    m_label->hide();
    m_border->hide();
    m_lock->hide();

    m_label->setDefaultTextColor(m_colCurrent);
    m_font.setFamily(Preferences::labelFontQString());
    int fontSize = exactFontSize(Preferences::labelFont(),
                                 Preferences::labelFontSizeMM());
    m_font.setPixelSize(fontSize);
    m_label->setFont(m_font);

    QString labelStr = QString::fromStdString( getViewObject()->Label.getValue() );
    m_label->setPlainText(labelStr);
    QRectF labelArea = m_label->boundingRect();                //m_label coords
    double labelWidth = m_label->boundingRect().width();
    double labelHeight = (1 - labelCaptionFudge) * m_label->boundingRect().height();

    QBrush b(Qt::NoBrush);
    m_border->setBrush(b);
    m_decorPen.setColor(m_colCurrent);
    m_border->setPen(m_decorPen);

    QRectF displayArea = customChildrenBoundingRect();
    double displayWidth = displayArea.width();
    double displayHeight = displayArea.height();
    QPointF displayCenter = displayArea.center();
    m_label->setX(displayCenter.x() - labelArea.width()/2.);
    m_label->setY(displayArea.bottom());

    double frameWidth = displayWidth;
    if (labelWidth > displayWidth) {
        frameWidth = labelWidth;
    }
    double frameHeight = labelHeight + displayHeight;

    QRectF frameArea = QRectF(displayCenter.x() - frameWidth/2.,
                              displayArea.top(),
                              frameWidth,
                              frameHeight);

    double lockX = frameArea.left();
    double lockY = frameArea.bottom() - m_lockHeight;
    if (feat->isLocked() &&
        feat->showLock()) {
        m_lock->setZValue(ZVALUE::LOCK);
        m_lock->setPos(lockX, lockY);
        m_lock->show();
    } else {
        m_lock->hide();
    }

    prepareGeometryChange();
    m_border->setRect(frameArea.adjusted(-2, -2, 2,2));
    m_border->setPos(0., 0.);

    m_label->show();
    if (getFrameState()) {
        m_border->show();
    }
}

void QGIView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QStyleOptionGraphicsItem myOption(*option);
    myOption.state &= ~QStyle::State_Selected;

    //    painter->setPen(Qt::red);
    //    painter->drawRect(boundingRect());          //good for debugging

    QGraphicsItemGroup::paint(painter, &myOption, widget);
}

QRectF QGIView::customChildrenBoundingRect() const
{
    QList<QGraphicsItem*> children = childItems();
    // exceptions not to be included in determining the frame rectangle
    QRectF result;
    for (auto& child : children) {
        if (!child->isVisible()) {
            continue;
        }
        if (child->type() != UserType::QGIViewDimension &&
            child->type() != UserType::QGILeaderLine &&
            child->type() != UserType::QGIRichAnno &&
            child->type() != UserType::QGEPath &&
            child->type() != UserType::QGMText &&
            child->type() != UserType::QGCustomBorder &&
            child->type() != UserType::QGCustomLabel &&
            child->type() != UserType::QGIWeldSymbol &&
            child->type() != UserType::QGICaption &&
            child->type() != UserType::QGICMark) {
            QRectF childRect = mapFromItem(child, child->boundingRect()).boundingRect();
            result = result.united(childRect);
        }
    }
    return result;
}

QRectF QGIView::boundingRect() const
{
    return m_border->rect().adjusted(-2., -2., 2., 2.);     //allow for border line width  //TODO: fiddle brect if border off?
}

QGIView* QGIView::getQGIVByName(std::string name)
{
    QList<QGraphicsItem*> qgItems = scene()->items();
    QList<QGraphicsItem*>::iterator it = qgItems.begin();
    for (; it != qgItems.end(); it++) {
        QGIView* qv = dynamic_cast<QGIView*>((*it));
        if (qv) {
            std::string qvName = qv->getViewNameAsString();
            if (name == qvName) {
                return (qv);
            }
        }
    }
    return nullptr;
}

/* static */
Gui::ViewProvider* QGIView::getViewProvider(App::DocumentObject* obj)
{
    if (obj) {
        Gui::Document* guiDoc = Gui::Application::Instance->getDocument(obj->getDocument());
        return guiDoc->getViewProvider(obj);
    }
    return nullptr;
}

MDIViewPage* QGIView::getMDIViewPage() const
{
    if (!getViewObject()) {
        return nullptr;
    }
    ViewProviderPage* vpp = getViewProviderPage(getViewObject());
    if (vpp) {
        return vpp->getMDIViewPage();
    }
    return nullptr;
}

ViewProviderPage* QGIView::getViewProviderPage(TechDraw::DrawView* dView)
{
    if (!dView)  {
        return nullptr;
    }
    TechDraw::DrawPage* page = dView->findParentPage();
    if (!page) {
        return nullptr;
    }

    Gui::Document* activeGui = Gui::Application::Instance->getDocument(page->getDocument());
    if (!activeGui) {
        return nullptr;
    }

    return freecad_cast<ViewProviderPage*>(activeGui->getViewProvider(page));
}

//remove a child of this from scene while keeping scene indexes valid
void QGIView::removeChild(QGIView* child)
{
    if (child && (child->parentItem() == this) ) {
        prepareGeometryChange();
        scene()->removeItem(child);
    }
}

bool QGIView::getFrameState()
{
    //    Base::Console().message("QGIV::getFrameState() - %s\n", getViewName());
    TechDraw::DrawView* dv = getViewObject();
    if (!dv) return true;

    TechDraw::DrawPage* page = dv->findParentPage();
    if (!page) return true;

    Gui::Document* activeGui = Gui::Application::Instance->getDocument(page->getDocument());
    Gui::ViewProvider* vp = activeGui->getViewProvider(page);
    ViewProviderPage* vpp = freecad_cast<ViewProviderPage*>(vp);
    if (!vpp) return true;

    return vpp->getFrameState();
}

void QGIView::hideFrame()
{
    m_border->hide();
    m_label->hide();
}

void QGIView::addArbitraryItem(QGraphicsItem* qgi)
{
    if (qgi) {
        //        m_randomItems.push_back(qgi);
        addToGroup(qgi);
        qgi->show();
    }
}

void QGIView::switchParentItem(QGIView *targetParent)
{
    auto currentParent = dynamic_cast<QGIView *>(this->parentItem());
    if (currentParent != targetParent) {
        if (targetParent) {
            targetParent->addToGroup(this);
            targetParent->updateView();
            if (currentParent) {
                currentParent->updateView();
            }
        }
        else {
            while (currentParent) {
                currentParent->removeFromGroup(this);
                currentParent->updateView();
                currentParent = dynamic_cast<QGIView *>(this->parentItem());
            }
        }
    }
}

void QGIView::setStack(int z)
{
    m_zOrder = z;
    setZValue(z);
    draw();
}

void QGIView::setStackFromVP()
{
    TechDraw::DrawView* feature = getViewObject();
    ViewProviderDrawingView* vpdv = static_cast<ViewProviderDrawingView*>
        (getViewProvider(feature));
    int z = vpdv->getZ();
    setStack(z);
}

QColor QGIView::prefNormalColor()
{
    return PreferencesGui::getAccessibleQColor(PreferencesGui::normalQColor());
}

QColor QGIView::getPreColor()
{
    return PreferencesGui::getAccessibleQColor(PreferencesGui::preselectQColor());
}

QColor QGIView::getSelectColor()
{
    return PreferencesGui::getAccessibleQColor(PreferencesGui::selectQColor());
}

Base::Reference<ParameterGrp> QGIView::getParmGroupCol()
{
    return App::GetApplication().GetUserParameter()
        .GetGroup("BaseApp")->GetGroup("Preferences")->GetGroup("Mod/TechDraw/Colors");
}

//convert input font size in mm to scene units
//note that when used to set font size this will result in
//text that is smaller than sizeInMillimetres.  If exactly
//correct sized text is required, use exactFontSize.
int QGIView::calculateFontPixelSize(double sizeInMillimetres)
{
    // Calculate font size in pixels by using resolution conversion
    // and round to nearest integer
    return (int) (Rez::guiX(sizeInMillimetres) + 0.5);
}

int QGIView::calculateFontPixelWidth(const QFont &font)
{
    // Return the width of digit 0, most likely the most wide digit
    return Gui::QtTools::horizontalAdvance(QFontMetrics(font), QChar::fromLatin1('0'));
}

const double QGIView::DefaultFontSizeInMM = 5.0;

void QGIView::dumpRect(const char* text, QRectF rect) {
    Base::Console().message("DUMP - %s - rect: (%.3f, %.3f) x (%.3f, %.3f)\n", text,
                            rect.left(), rect.top(), rect.right(), rect.bottom());
}

//determine the required font size to generate text with upper case
//letter height = nominalSize
int QGIView::exactFontSize(std::string fontFamily, double nominalSize)
{
    double sceneSize = Rez::guiX(nominalSize);      //desired height in scene units
    QFont font;
    font.setFamily(QString::fromUtf8(fontFamily.c_str()));
    font.setPixelSize(sceneSize);

    QFontMetricsF fm(font);
    double capHeight = fm.capHeight();
    double ratio = sceneSize / capHeight;
    return (int) sceneSize * ratio;
}

void QGIView::makeMark(double xPos, double yPos, QColor color)
{
    QGIVertex* vItem = new QGIVertex(-1);
    vItem->setParentItem(this);
    vItem->setPos(xPos, yPos);
    vItem->setWidth(2.0);
    vItem->setRadius(20.0);
    vItem->setNormalColor(color);
    vItem->setFillColor(color);
    vItem->setPrettyNormal();
    vItem->setZValue(ZVALUE::VERTEX);
}

void QGIView::makeMark(Base::Vector3d pos, QColor color)
{
    makeMark(pos.x, pos.y, color);
}

void QGIView::makeMark(QPointF pos, QColor color)
{
    makeMark(pos.x(), pos.y(), color);
}

//! Retrieves objects of type T with given indexes
template <typename T>
std::vector<T> QGIView::getObjects(std::vector<int> indexes)
{
    QList<QGraphicsItem*> children = childItems();
    std::vector<T> result;
    for (QGraphicsItem*& child : children) {
        //                   Convert QGIVertex* (as T) to QGIVertex
        if (child->type() != std::remove_pointer<T>::type::Type) {
            continue;
        }

        // Get index of child item
        T object = static_cast<T>(child);
        int target = object->getProjIndex();
        // If child item's index in indexes, then add to results
        if (std::ranges::find(indexes, target) != indexes.end()) {
            result.push_back(object);
        }
    }
    return result;
}

template std::vector<QGIVertex*> QGIView::getObjects<QGIVertex*>(std::vector<int>);
template std::vector<QGIEdge*> QGIView::getObjects<QGIEdge*>(std::vector<int>);


#include <Mod/TechDraw/Gui/moc_QGIView.cpp>
