#include "ImageViewerWidget.h"
#include "DicomSeriesLoader.h"
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <QWheelEvent>

ImageViewerWidget::ImageViewerWidget(std::shared_ptr<DicomSeries> series, QWidget* parent)
    : QVTKOpenGLNativeWidget(parent), m_series(series) {
    auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    setRenderWindow(renderWindow);
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderWindow->AddRenderer(renderer);
    // TODO: setup VTK pipeline with image data from series
}

void ImageViewerWidget::setSlice(int slice) {
    if (slice == m_currentSlice) return;
    m_currentSlice = slice;
    emit sliceChanged(slice);
    // update VTK view
}

void ImageViewerWidget::setZoom(double zoom) {
    if (zoom == m_zoom) return;
    m_zoom = zoom;
    emit zoomChanged(zoom);
    // update VTK camera zoom
}
