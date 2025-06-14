#include "MainWindow.h"
#include "ImageViewerWidget.h"
#include <QGridLayout>
#include <QMenuBar>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), m_centralWidget(new QWidget(this)), m_layout(new QGridLayout(m_centralWidget)) {
    setWindowTitle("DICOM Viewer");
    setupUI();
}

void MainWindow::setupUI() {
    setCentralWidget(m_centralWidget);
    menuBar()->addAction("Load Series", [this]() {
        QString dir = QFileDialog::getExistingDirectory(this, "Select DICOM Folder");
        if (!dir.isEmpty()) {
            auto series = m_manager.loadSeries(dir);
            if (series) {
                auto viewer = new ImageViewerWidget(series, m_centralWidget);
                m_viewers.append(viewer);
                int row = m_viewers.size() / 2;
                int col = m_viewers.size() % 2;
                m_layout->addWidget(viewer, row, col);
                connect(viewer, &ImageViewerWidget::sliceChanged, &m_manager, &StudyManager::onSliceChanged);
                connect(viewer, &ImageViewerWidget::zoomChanged, &m_manager, &StudyManager::onZoomChanged);
                connect(&m_manager, &StudyManager::sliceChanged, viewer, &ImageViewerWidget::setSlice);
                connect(&m_manager, &StudyManager::zoomChanged, viewer, &ImageViewerWidget::setZoom);
            }
        }
    });
}
