# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD$

PORTNAME=	opencv
DISTVERSION=	4.4.0
CATEGORIES=	graphics

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

BUILD_DEPENDS=	${_${_OCV_PACKAGE}_BUILD_DEPENDS}
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		${_${_OCV_PACKAGE}_LIB_DEPENDS}
RUN_DEPENDS=	bash:shells/bash \
		${_${_OCV_PACKAGE}_RUN_DEPENDS}

USES=		cmake compiler:c++14-lang gnome jpeg localbase:ldflags pkgconfig \
		shebangfix
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_GSTREAMER1=	yes

SHEBANG_FILES=	cmake/templates/setup_vars_linux.sh.in

USE_GITHUB=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	OCV_VERSION=${DISTVERSION} \
		OCV_SHLIB_VERSION=${DISTVERSION:R}

# Subpackage handling
_disabled_OCV_MODULES=	aruco bgsegm bioinspired ccalib cnn_3dobj \
			cudaarithm cudabgsegm cudacodec cudafeatures2d \
			cudafilters cudaimgproc cudalegacy cudaobjdetect \
			cudaoptflow cudastereo cudawarping cudev \
			cvv datasets dnn_objdetect dnns_easily_fooled \
			dpm face freetype fuzzy hdf hfs img_hash \
			line_descriptor matlab optflow ovis phase_unwrapping \
			plot quality reg rgbd saliency sfm shape stereo \
			structured_light superres surface_matching text \
			tracking videostab viz xfeatures2d ximgproc \
			xobjdetect xphoto

_default_LIB_DEPENDS=	libtesseract.so:graphics/tesseract \
			libavcodec.so:multimedia/ffmpeg \
			libIlmImf-2_5.so:graphics/openexr \
			libopenblas.so:math/openblas \
			libopenjp2.so:graphics/openjpeg \
			libpng16.so:graphics/png \
			libtiff.so:graphics/tiff \
			libwebp.so:graphics/webp \
			libopencv_core.so:graphics/opencv-core
_default_OCV_MODULES=	apps calib3d contrib dnn features2d flann gapi \
			highgui imgcodecs ml objdetect photo stitching \
			ts video videoio

_core_OCV_MODULES=	core imgproc

_python_LIB_DEPENDS=	libopencv_core.so:graphics/opencv-core \
			libopencv_imgproc.so:graphics/opencv-core \
			libopencv_ml.so:graphics/opencv
_python_OCV_MODULES=	python3

_java_USES=		python:build
_java_LIB_DEPENDS=	libopencv_ml.so:graphics/opencv
_java_OCV_MODULES=	java

_OCV_PACKAGES=		default core python java disabled

# Main package
_OCV_PACKAGE?=		default

# Disable the modules of the other subpackages
.  for _package in ${_OCV_PACKAGES:N${_OCV_PACKAGE}}
.    for _ocv_module in ${_${_package}_OCV_MODULES}
CMAKE_ARGS+=	-DBUILD_opencv_${_ocv_module}:BOOL=FALSE
.    endfor
.  endfor
# Enable modules for the given subpackage
.  for _ocv_module in ${_${_OCV_PACKAGE}_OCV_MODULES}
CMAKE_ARGS+=	-DBUILD_opencv_${_ocv_module}:BOOL=TRUE
.  endfor

.include <bsd.port.mk>
