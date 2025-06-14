cmake_minimum_required(VERSION 3.16)
project(DicomViewer)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(VTK REQUIRED)
find_package(DCMTK REQUIRED)

set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/StudyManager.cpp
    src/DicomSeriesLoader.cpp
    src/ImageViewerWidget.cpp
)

set(HEADERS
    src/MainWindow.h
    src/StudyManager.h
    src/DicomSeriesLoader.h
    src/ImageViewerWidget.h
)

add_executable(dicomviewer ${SOURCES} ${HEADERS})

target_link_libraries(dicomviewer PRIVATE Qt6::Widgets ${VTK_LIBRARIES} DCMTK::dcmdata DCMTK::oflog)

if (VTK_VERSION VERSION_LESS "9")
    include(${VTK_USE_FILE})
endif()

enable_testing()
add_subdirectory(tests)
