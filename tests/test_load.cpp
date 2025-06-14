#include <QtTest/QtTest>
#include "DicomSeriesLoader.h"

class TestLoad : public QObject {
    Q_OBJECT
private slots:
    void loadSeries();
};

void TestLoad::loadSeries() {
    auto series = DicomSeriesLoader::load("./");
    QVERIFY(series != nullptr);
}

QTEST_MAIN(TestLoad)
#include "test_load.moc"
