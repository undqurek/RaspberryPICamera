LIBS += \
        -L'/opt/vc/lib/' \
	-l'raspicam' \
	-l'mmal' \
	-l'mmal_core' \
	-l'mmal_util'

INCLUDEPATH += \
	/usr/local/include

HEADERS += \
    camera.h

SOURCES += \
	main.cpp \
    camera.cpp

FORMS +=
