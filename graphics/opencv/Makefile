# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD$

PORTNAME=	opencv
PORTVERSION=	3.4.7
CATEGORIES?=	graphics

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

.if defined(OCV_CORE)
BUILD_DEPENDS=	protoc:devel/protobuf
.else
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libtesseract.so:graphics/tesseract \
		libhdf5.so:science/hdf5 \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog
BUILD_DEPENDS=	${LOCALBASE}/lib/libopencv_core.so:graphics/opencv-core
RUN_DEPENDS=	${LOCALBASE}/lib/libopencv_core.so:graphics/opencv-core
.endif

USES+=		cmake compiler:c++14-lang gnome localbase:ldflags pkgconfig

USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11

DATADIR=	${PREFIX}/share/OpenCV
PLIST_SUB+=	SOVERSION=${DISTVERSION:R} VERSION=${DISTVERSION}

# Explicitely force a fail if configure mismatches expectations
CMAKE_OFF+=	ENABLE_CONFIG_VERIFICATION

# Don't generate bash script
CMAKE_OFF+=	OPENCV_GENERATE_SETUPVARS USE_IPPICV

# 3rd party libs
CMAKE_ON+=	ENABLE_CXX11 PROTOBUF_UPDATE_FILES
CMAKE_OFF+=	BUILD_ZLIB BUILD_TIFF BUILD_JASPER BUILD_JPEG BUILD_PNG \
		BUILD_OPENEXR BUILD_WEBP BUILD_TBB BUILD_PROTOBUF

# Optional 3rd party components
# always off (not supported on FreeBSD or difficult to deal with in ports)
CMAKE_OFF+=	WITH_CPUFEATURES WITH_CUBLAS WITH_CUDA WITH_CUFFT \
		WITH_INF_ENGINE WITH_NVCUVID WITH_OPENNI WITH_OPENNI2
# OpenCV build components
CMAKE_OFF+=	BUILD_FAT_JAVA_LIB BUILD_PACKAGE BUILD_PERF_TESTS \
		BUILD_TESTS BUILD_WITH_DEBUG_INFO
# OpenCV installation options
CMAKE_OFF+=	INSTALL_CREATE_DISTRIB
# OpenCV build options
CMAKE_OFF+=	ENABLE_CCACHE ENABLE_FLAKE8 ENABLE_PYLINT
CMAKE_ON+=	ENABLE_OMIT_FRAME_POINTER

CMAKE_OFF+=	WITH_VTK WITH_CAROTENE WITH_QUIRC \
		WITH_GTK WITH_QT WITH_OPENGL \
		WITH_VA WITH_ITT

SUB_FILES=	FindOpenCVCore.cmake
SUB_LIST=	OCV_VERSION=${DISTVERSION}

OCV_CORE_MODS=		core imgproc
OCV_MODS=		apps calib3d contrib dnn features2d flann highgui \
			imgcodecs ml objdetect photo shape stitching \
			superres ts video videoio videostab
OCV_JAVA_MODS=		java
OCV_PYTHON_MODS=	python3

OPTIONS_DEFINE=		EXAMPLES EXTRA_MODULES
OPTIONS_GROUP=		PERFORMANCE IMAGE VIDEO
OPTIONS_GROUP_PERFORMANCE=	EIGEN3 OPENCL TBB
OPTIONS_GROUP_IMAGE=	GDAL GDCM JASPER JPEG OPENEXR PNG TIFF WEBP
OPTIONS_GROUP_VIDEO=	ARAVIS DC1394 FFMPEG GPHOTO2 GSTREAMER MFX V4L
OPTIONS_DEFAULT=	EIGEN3 EXTRA_MODULES FFMPEG JASPER JPEG PNG TIFF WEBP V4L \
			${MACHINE_CPU:tu}
OPTIONS_SUB=		yes
.if defined(OCV_CORE)
OPTIONS_EXCLUDE=	${OPTIONS_GROUP_VIDEO} ${OPTIONS_GROUP_IMAGE}
.elif defined(OCV_SLAVE)
OPTIONS_EXCLUDE=	EXAMPLES
.endif

DC1394_DESC=		IEEE 1394 camera support
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394
DC1394_CMAKE_BOOL=	WITH_1394

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

PERFORMANCE_DESC=	Performance enhancing libraries

EIGEN3_DESC=		Eigen 3 support
EIGEN3_USES=		eigen:3
EIGEN3_CMAKE_BOOL=	WITH_EIGEN

OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl
OPENCL_RUN_DEPENDS=	opencl>=0:devel/opencl
OPENCL_CMAKE_BOOL=	WITH_OPENCL

TBB_DESC=		Parallel processing support via TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb
TBB_CMAKE_BOOL=		WITH_TBB

IMAGE_DESC=		Image format support

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_CMAKE_BOOL=	WITH_JASPER

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	WITH_JPEG

GDAL_DESC=		Geospatial Data Abstraction Library
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
GDAL_CMAKE_BOOL=	WITH_GDAL

GDCM_DESC=		Open source DICOM library
GDCM_LIB_DEPENDS=	libgdcmMSFF.so:devel/gdcm
GDCM_CMAKE_BOOL=	WITH_GDCM

MFX_DESC=		Intel MediaSDK (aka Quick Sync Video)
MFX_LIB_DEPENDS=	libmfx.so:multimedia/intel-media-sdk \
			libva-drm.so:multimedia/libva
MFX_CONFIGURE_ENV=	MFX_HOME="${LOCALBASE}"
MFX_CMAKE_BOOL=		WITH_MFX

OPENEXR_LIB_DEPENDS=	libHalf.so:graphics/ilmbase \
			libIlmImf.so:graphics/openexr
OPENEXR_CMAKE_BOOL=	WITH_OPENEXR

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL=		WITH_PNG

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	WITH_TIFF

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=	WITH_WEBP

VIDEO_DESC=		Video support

ARAVIS_DESC=		Aravis SDK
ARAVIS_LIB_DEPENDS=	libaravis-0.6.so:devel/libaravis
ARAVIS_CMAKE_BOOL=	WITH_ARAVIS

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

GPHOTO2_DESC=		Gphoto2 camera support
GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO2_CMAKE_BOOL=	WITH_GPHOTO2

GSTREAMER_USE=		GSTREAMER1=yes GNOME=glib20
GSTREAMER_USES=		gettext-runtime
GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER

V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CMAKE_BOOL=		WITH_V4L WITH_LIBV4L
V4L_CMAKE_ON=		CMAKE_REQUIRED_INCLUDES:STRING=${LOCALBASE}/include

EXTRA_MODULES_DESC=		Build OpenCV contrib modules
EXTRA_MODULES_GH_PROJECT=	opencv_contrib:extra_mod \
				opencv_3rdparty:extra_mod_3rdparty_boost_descr \
				opencv_3rdparty:extra_mod_3rdparty_vgg_descr \
				opencv_3rdparty:extra_mod_face
EXTRA_MODULES_GH_TAGNAME=	${PORTVERSION}:extra_mod \
				34e4206aef44d50e6bbcd0ab06354b52e7466d26:extra_mod_3rdparty_boost_descr \
				fccf7cd6a4b12079f73bbfb21745f9babcd4eb1d:extra_mod_3rdparty_vgg_descr \
				8afa57abc8229d611c4937165d20e2a2d9fc5a12:extra_mod_face
EXTRA_MODULES_CMAKE_BOOL_OFF=	BUILD_opencv_matlab
EXTRA_MODULES_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules_sfm_src__libmv__light_libmv_numeric_numeric.h \
				${FILESDIR}/extra-patch-modules_sfm_src_libmv__light_libmv_numeric_numeric.cc \
				${FILESDIR}/extra-patch-modules_xobjdetect_tools_waldboost__detector_CMakeLists.txt
EXTRA_MODULES_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
				libharfbuzz.so:print/harfbuzz \
				libsz.so:science/szip
EXTRA_MODULES_WRKSRC=		${WRKDIR}/${PORTNAME}_contrib-${PORTVERSION}/
EXTRA_MODULES_VARS=		LDFLAGS+=-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT} \
				LDFLAGS+=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so
EXTRA_MODULES_CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH=${LOCALBASE}/lib;${LOCALBASE}/lib/gcc${GCC_DEFAULT}
EXTRA_MODULES_BUILD_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so:lang/gcc${GCC_DEFAULT}
EXTRA_MODULES_RUN_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so:lang/gcc${GCC_DEFAULT}

OCV_LIBDIR=		${LOCALBASE}/lib
.if defined(OCV_CORE)
.  for module in ${OCV_MODS} ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_OFF+=		BUILD_opencv_${module}
.  endfor
.elif defined(OCV_PYTHON)
_PYTHON_FEATURE_FLAVORS=	yes
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${OCV_LIBDIR}/libopencv_ml.so.${DISTVERSION}:graphics/opencv
USES+=		python:3.6+
USE_PYTHON=	flavors
CMAKE_ON+=	BUILD_opencv_python3
.  for module in apps java stitching superres videostab
CMAKE_OFF+=	BUILD_opencv_${module}
.  endfor
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}/modules/python3
EXAMPLES_CMAKE_BOOL+=	INSTALL_PYTHON_EXAMPLES

.elif defined(OCV_JAVA)
BUILD_DEPENDS+=	ant:devel/apache-ant
USES+=		python:build
USE_JAVA=	yes
CMAKE_ON+=	BUILD_opencv_java \
		BUILD_JAVA
.  for module in apps js python3 shape stitching superres ts \
		videostab viz
CMAKE_OFF+=	BUILD_opencv_${module}
.  endfor
CONFIGURE_ENV+=	JAVA_HOME="${JAVA_HOME}"
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}/modules/java

.else
EXAMPLES_CMAKE_BOOL+=	INSTALL_C_EXAMPLES
.  for module in ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_OFF+=	BUILD_opencv_${module}
.  endfor
.endif

.if !defined(OCV_JAVA)
CMAKE_OFF+=	BUILD_JAVA
.endif

post-extract-EXTRA_MODULES-on:
	@${MKDIR} ${CONFIGURE_WRKSRC}/downloads/xfeatures2d
	@${MV} ${WRKSRC_extra_mod_3rdparty_boost_descr}/* ${CONFIGURE_WRKSRC}/downloads/xfeatures2d/
	@${MV} ${WRKSRC_extra_mod_3rdparty_vgg_descr}/* ${CONFIGURE_WRKSRC}/downloads/xfeatures2d/
	@${MKDIR} ${CONFIGURE_WRKSRC}/share/OpenCV/testdata/cv/face
	@${MV} ${WRKSRC_extra_mod_face}/* ${CONFIGURE_WRKSRC}/share/OpenCV/testdata/cv/face/

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s|$${OPENCV_LIB_INSTALL_PATH}|libdata|' \
		 ${WRKSRC}/cmake/OpenCVGenPkgconfig.cmake
	@${REINPLACE_CMD} -e 's|$${OpenCV_SOURCE_DIR}/3rdparty/include/opencl/1.2|${LOCALBASE}/include/CL|g' \
		 ${WRKSRC}/cmake/OpenCVDetectOpenCL.cmake
	@${REINPLACE_CMD} -e 's|share/OpenCV/doc|${DOCSDIR_REL}|g' \
		-e 's|share/OpenCV/samples|${EXAMPLESDIR_REL}|g' \
		${WRKSRC}/CMakeLists.txt
.if defined(OCV_CORE)
	@${REINPLACE_CMD} -e 's|opencv.pc|opencv-core.pc|g' \
		${WRKSRC}/cmake/OpenCVGenPkgconfig.cmake
	@${REINPLACE_CMD} -e 's|Name:.*|Name: OpenCV-core|' \
		${WRKSRC}/cmake/templates/opencv-XXX.pc.in
.elif defined(OCV_SLAVE)
	@${REINPLACE_CMD} -e 's|add_subdirectory(data)||g' \
		${WRKSRC}/CMakeLists.txt
.endif
	@${FIND} ${WRKSRC} -name '*.bak' -exec ${RM} {} \;

post-install:
.if !defined(OCV_SLAVE)
	(cd ${STAGEDIR}${PREFIX} && \
		${RM} -r include/opencv2/core \
			include/opencv2/core.hpp \
			include/opencv2/imgproc \
			include/opencv2/imgproc.hpp \
			include/opencv2/cvconfig.h \
			include/opencv/cvwimage.h \
			include/opencv/cxcore.h \
			include/opencv/cxcore.hpp \
			include/opencv/cxeigen.hpp \
			include/opencv/cxmisc.h \
			lib/libopencv_core* \
			lib/libopencv_imgproc*)
.endif
.if defined(OCV_CORE)
	(cd ${STAGEDIR}${PREFIX} && \
		${RM} include/opencv/cv.h \
			include/opencv/cv.hpp \
			include/opencv/cvaux.h \
			include/opencv/cvaux.hpp \
			include/opencv/highgui.h \
			include/opencv/ml.h )
	${RM} -r ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmake/Modules
	${INSTALL_DATA} ${WRKDIR}/FindOpenCVCore.cmake \
		${STAGEDIR}${PREFIX}/share/cmake/Modules/
.endif
.if defined(OCV_PYTHON)
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S|${PREFIX}/||} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S|${PREFIX}/||})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/python && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/python
.endif

post-install-EXAMPLES-on:
.if defined(OCV_JAVA)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/java && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/java
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXTRA_MODULES} && !defined(OCV_CORE)
CMAKE_ARGS+=	-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/opencv_contrib-${PORTVERSION}/modules
.endif

.include <bsd.port.post.mk>
