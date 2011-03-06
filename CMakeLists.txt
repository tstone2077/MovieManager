CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

PROJECT (ApplicationName)
SET (QT_USE_QTXML YES)

# set qt specific variables
FIND_PACKAGE (Qt4 REQUIRED)

# this include will add qt include directories to the build process and set the QT_LIBRARIES variable that we'll use when linking
INCLUDE (${QT_USE_FILE})



SET (CLIENT_BINARY_NAME "GuiApp")

SET ( SOURCES
        "src/main.cpp"
        "src/MainWindow.cpp"
        "src/MainApp.cpp"
        "src/FirstDockWidget.cpp"
        "src/WorkbenchWidget.cpp"
    )

# Files to be Moc'd by Qt
SET ( MOC_INPUT
        "inc/MainWindow.h"
        "inc/MainApp.h"
        "inc/FirstDockWidget.h"
        "inc/WorkbenchWidget.h"
    )

# Set include directories
INCLUDE_DIRECTORIES ("inc")

# run moc over the files
# MOC_OUTPUT stores the generated files
QT4_WRAP_CPP (MOC_OUTPUT ${MOC_INPUT})

# add mira resources
QT4_ADD_RESOURCES(RESOURCES "resources/Resources.qrc")

# set the generated executable path
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")

# add our target
ADD_EXECUTABLE (${CLIENT_BINARY_NAME} WIN32 ${SOURCES} ${MOC_OUTPUT} ${RESOURCES}) 

# link
  TARGET_LINK_LIBRARIES (${CLIENT_BINARY_NAME} ${QT_LIBRARIES} )

IF (WIN32)
   #Copy the Qt Dlls
   CONFIGURE_FILE(${QT_BINARY_DIR}/QtGuid4.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QtGuid4.dll
                    COPYONLY)
   CONFIGURE_FILE(${QT_BINARY_DIR}/QtGui4.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QtGui4.dll
                    COPYONLY)

   CONFIGURE_FILE(${QT_BINARY_DIR}/QtCored4.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QtCored4.dll
                    COPYONLY)
   CONFIGURE_FILE(${QT_BINARY_DIR}/QtCore4.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QtCore4.dll
                    COPYONLY)


   CONFIGURE_FILE(${QT_BINARY_DIR}/QtXmld4.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QtXmld4.dll
                    COPYONLY)
   CONFIGURE_FILE(${QT_BINARY_DIR}/QtXml4.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QtXml4.dll
                    COPYONLY)
ELSE(WIN32)
ENDIF(WIN32)

