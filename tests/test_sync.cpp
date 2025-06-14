#include <QtTest/QtTest>
#include "StudyManager.h"
#include "DicomSeriesLoader.h"

class DummyViewer : public QObject {
    Q_OBJECT
public slots:
    void setSlice(int s) { m_slice = s; }
    void setZoom(double z) { m_zoom = z; }
signals:
    void sliceChanged(int slice);
    void zoomChanged(double zoom);
public:
    int m_slice = 0;
    double m_zoom = 1.0;
};

class TestSync : public QObject {
    Q_OBJECT
private slots:
    void syncNavigation();
};

void TestSync::syncNavigation() {
    StudyManager mgr;
    auto series = std::make_shared<DicomSeries>();
    mgr.loadSeries("./");
    DummyViewer v1, v2;
    QObject::connect(&v1, &DummyViewer::sliceChanged, &mgr, &StudyManager::onSliceChanged);
    QObject::connect(&v2, &DummyViewer::sliceChanged, &mgr, &StudyManager::onSliceChanged);
    QObject::connect(&mgr, &StudyManager::sliceChanged, &v1, &DummyViewer::setSlice);
    QObject::connect(&mgr, &StudyManager::sliceChanged, &v2, &DummyViewer::setSlice);
    emit v1.sliceChanged(5);
    QCOMPARE(v1.m_slice, 5);
    QCOMPARE(v2.m_slice, 5);
}

QTEST_MAIN(TestSync)
#include "test_sync.moc"
