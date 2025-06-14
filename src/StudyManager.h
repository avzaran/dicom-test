#pragma once
#include <QObject>
#include <memory>
#include <vector>
class DicomSeries;

class StudyManager : public QObject {
    Q_OBJECT
public:
    explicit StudyManager(QObject* parent = nullptr);
    std::shared_ptr<DicomSeries> loadSeries(const QString& dir);

signals:
    void sliceChanged(int slice);
    void zoomChanged(double zoom);

public slots:
    void onSliceChanged(int slice);
    void onZoomChanged(double zoom);

private:
    std::vector<std::shared_ptr<DicomSeries>> m_series;
    bool m_block = false;
};
