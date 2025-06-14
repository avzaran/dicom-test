#include <QtTest/QtTest>
#include "ImageViewerWidget.h"

class TestMeasure : public QObject {
    Q_OBJECT
private slots:
    void dummyMeasure();
};

void TestMeasure::dummyMeasure() {
    auto series = std::make_shared<DicomSeries>();
    ImageViewerWidget w(series);
    w.setSlice(1);
    QCOMPARE(w.property("dummy").isValid(), false);
}

QTEST_MAIN(TestMeasure)
#include "test_measure.moc"
