# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = toh-TMP007

CONFIG += sailfishapp

QT += sensors

SOURCES += src/toh-TMP007.cpp \
    src/adafruit_tmp007.cpp \
    src/driverBase.cpp \
    src/irtempsensor.cpp \
    src/tohvdd.cpp

OTHER_FILES += qml/toh-TMP007.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/toh-TMP007.changes.in \
    rpm/toh-TMP007.spec \
    rpm/toh-TMP007.yaml \
    translations/*.ts \
    toh-TMP007.desktop

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/toh-TMP007-de.ts

HEADERS += \
    src/adafruit_tmp007.h \
    src/driverBase.h \
    src/irtempsensor.h \
    src/tohvdd.h

