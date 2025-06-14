#pragma once
#include <QMainWindow>
#include "StudyManager.h"

class ImageViewerWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
private:
    StudyManager m_manager;
    QWidget* m_centralWidget;
    QGridLayout* m_layout;
    QList<ImageViewerWidget*> m_viewers;
    void setupUI();
};
