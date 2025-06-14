#pragma once
#include <QWidget>
#include <vtkSmartPointer.h>
#include <QVTKOpenGLNativeWidget.h>

class DicomSeries;

class ImageViewerWidget : public QVTKOpenGLNativeWidget {
    Q_OBJECT
public:
    explicit ImageViewerWidget(std::shared_ptr<DicomSeries> series, QWidget* parent = nullptr);
    void setSlice(int slice);
    void setZoom(double zoom);
signals:
    void sliceChanged(int slice);
    void zoomChanged(double zoom);
private:
    std::shared_ptr<DicomSeries> m_series;
    int m_currentSlice = 0;
    double m_zoom = 1.0;
};
