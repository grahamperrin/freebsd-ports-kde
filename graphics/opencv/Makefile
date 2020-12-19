# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD$

PORTNAME=	opencv
PORTVERSION=	3.4.7
CATEGORIES=	graphics

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

.if defined(OCV_CORE)
BUILD_DEPENDS=	protoc:devel/protobuf
.else
LIB_DEPENDS=	libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libhdf5.so:science/hdf5 \
		libprotobuf.so:devel/protobuf
BUILD_DEPENDS=	${LOCALBASE}/lib/libopencv_core.so:graphics/opencv-core
RUN_DEPENDS=	${LOCALBASE}/lib/libopencv_core.so:graphics/opencv-core
.endif

USES+=		cmake compiler:c++14-lang gnome localbase:ldflags pkgconfig

USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11

DATADIR=	${PREFIX}/share/OpenCV
PLIST_SUB+=	SOVERSION=${DISTVERSION:R} VERSION=${DISTVERSION}

CMAKE_OFF+=	OPENCV_GENERATE_SETUPVARS

# 3rd party libs
CMAKE_ON+=	ENABLE_CXX11 PROTOBUF_UPDATE_FILES
CMAKE_OFF+=	BUILD_ZLIB BUILD_TIFF BUILD_JASPER BUILD_JPEG BUILD_PNG \
		BUILD_OPENEXR BUILD_WEBP BUILD_TBB BUILD_PROTOBUF
# Optional 3rd party components
# always off (not supported on FreeBSD or difficult to deal with in ports)
CMAKE_OFF+=	WITH_CPUFEATURES WITH_CUDA WITH_CUFFT WITH_CUBLAS \
		WITH_NVCUVID WITH_INF_ENGINE WITH_OPENNI WITH_OPENNI2
# Options
CMAKE_OFF+=	OPENCV_ENABLE_NONFREE \
		WITH_1394 \
		WITH_ARAVIS \
		WITH_CAROTENE \
		WITH_CLP \
		WITH_EIGEN \
		WITH_FFMPEG \
		WITH_GDAL \
		WITH_GDCM \
		WITH_GIGEAPI \
		WITH_GPHOTO2 \
		WITH_GSTREAMER \
		WITH_GSTREAMER_0_10 \
		WITH_GTK \
		WITH_GTK_2_X \
		WITH_HALIDE \
		WITH_IMGCODEC_HDR \
		WITH_IMGCODEC_PXM \
		WITH_IMGCODEC_SUNRASTER \
		WITH_IPP \
		WITH_ITT \
		WITH_JASPER \
		WITH_JPEG \
		WITH_LAPACK \
		WITH_LIBV4L \
		WITH_OPENCL \
		WITH_OPENCLAMDBLAS \
		WITH_OPENCLAMDFFT \
		WITH_OPENCL_SVM \
		WITH_OPENEXR \
		WITH_OPENGL \
		WITH_OPENMP \
		WITH_OPENVX \
		WITH_PNG \
		WITH_PTHREADS_PF \
		WITH_PVAPI \
		WITH_QT \
		WITH_QUIRC \
		WITH_TBB \
		WITH_TIFF \
		WITH_UNICAP \
		WITH_V4L \
		WITH_VA \
		WITH_VA_INTEL \
		WITH_VTK \
		WITH_WEBP \
		WITH_XIMEA \
		WITH_XINE
# OpenCV build components
CMAKE_ON+=	BUILD_SHARED_LIBS \
		BUILD_opencv_apps \
		WITH_PROTOBUF
CMAKE_OFF+=	BUILD_CUDA_STUBS \
		BUILD_DOCS \
		BUILD_EXAMPLES \
		BUILD_FAT_JAVA_LIB \
		BUILD_IPP_IW \
		BUILD_JAVA \
		BUILD_PACKAGE \
		BUILD_PERF_TESTS \
		BUILD_TESTS \
		BUILD_WITH_DEBUG_INFO \
		BUILD_WITH_DYNAMIC_IPP \
		BUILD_opencv_js \
		BUILD_opencv_world
# OpenCV installation options
CMAKE_OFF+=	INSTALL_CREATE_DISTRIB \
		INSTALL_C_EXAMPLES \
		INSTALL_PYTHON_EXAMPLES \
		INSTALL_TESTS \
		INSTALL_TO_MANGLED_PATHS
# OpenCV build options
CMAKE_ARGS+=	ENABLE_CCACHE \
		ENABLE_PRECOMPILED_HEADERS \
		ENABLE_PROFILING \
		ENABLE_COVERAGE \
		ENABLE_POWERPC \
		ENABLE_FAST_MATH \
		ENABLE_NEON \
		ENABLE_VFPV3 \
		ENABLE_NOISY_WARNINGS \
		OPENCV_WARNINGS_ARE_ERRORS \
		ENABLE_IMPL_COLLECTION \
		ENABLE_INSTRUMENTATION \
		ENABLE_GNU_STL_DEBUG \
		ENABLE_BUILD_HARDENING \
		ENABLE_LTO \
		ENABLE_THIN_LTO \
		GENERATE_ABI_DESCRIPTOR \
		CV_DISABLE_OPTIMIZATION \
		OPENCV_GENERATE_SETUPVARS \
		ENABLE_CONFIG_VERIFICATION \
		ENABLE_PYLINT \
		ENABLE_FLAKE8
CMAKE_ON+=	ENABLE_OMIT_FRAME_POINTER \
		CV_ENABLE_INTRINSICS \
		CV_TRACE \

SUB_FILES=	FindOpenCVCore.cmake
SUB_LIST=	OCV_VERSION=${DISTVERSION}

OCV_CORE_MODS=		core imgproc
OCV_MODS=		apps calib3d contrib dnn features2d flann highgui \
			imgcodecs ml objdetect photo shape stitching \
			superres ts video videoio videostab
OCV_VTK_MODS=		viz
OCV_JAVA_MODS=		java
OCV_PYTHON_MODS=	python2 python3
OCV_JS_MODS=		js

OPTIONS_DEFINE=		CERES DOXYGEN EXAMPLES EXTRA_MODULES ITT NONFREE \
			QUIRC TESSERACT TESTS VA
OPTIONS_GROUP=		PERFORMANCE IMAGE VIDEO TOOLKITS
OPTIONS_RADIO=		BLASLIB PARALLEL
OPTIONS_RADIO_BLASLIB=	ATLAS NETLIB OPENBLAS
OPTIONS_RADIO_PARALLEL=	OPENMP TBB
OPTIONS_GROUP_PERFORMANCE=	CAROTENE COINMP EIGEN3 IPP NEON OPENCL VFPV3
OPTIONS_GROUP_IMAGE=	GDAL GDCM HDR JASPER JPEG OPENEXR PNG PXM SUNRASTER \
			TIFF WEBP
OPTIONS_GROUP_VIDEO=	ARAVIS DC1394 FFMPEG GPHOTO2 GSTREAMER MFX V4L
OPTIONS_GROUP_TOOLKITS=	GTK2 GTK3 OGRE OPENGL QT VTK
OPTIONS_DEFAULT=	EIGEN3 FFMPEG JASPER JPEG PNG TIFF WEBP V4L \
			EXTRA_MODULES
OPTIONS_SUB=		yes
.if defined(OCV_CORE)
OPTIONS_EXCLUDE=	CERES COINMP DOXYGEN EXAMPLES EXTRA_MODULES NONFREE \
			TESSERACT TESTS GTK2 GTK3 IPP ITT OPENCL \
			OPENGL OGRE QT VTK \
			ARAVIS DC1394 FFMPEG GSTREAMER V4L \
			GDAL GDCM GPHOTO2 HDR JASPER JPEG \
			OPENEXR PNG PXM QUIRC SUNRASTER TIFF WEBP
.elif defined(OCV_SLAVE)
.else
USES+=			python:3.2+,build
.endif

CERES_DESC=		Ceres sover (needed by contrib_sfm mod.)
CERES_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Ceres
CERES_LIB_DEPENDS=	libceres.so:math/ceres-solver

DC1394_DESC=		IEEE 1394 camera support
DC1394_LIB_DEPENDS=	libdc1394.so:multimedia/libdc1394
DC1394_CMAKE_BOOL=	WITH_1394

DOXYGEN_CMAKE_BOOL=	BUILD_DOCS BUILD_opencv_docs
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			py${PYTHON_DEFAULT:S/.//}-beautifulsoup>0:www/py-beautifulsoup

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

IPP_DESC=		ippicv library (amd64 only)
IPP_GH_PROJECT=		opencv_3rdparty:ipp
IPP_GH_TAGNAME=		32e315a5b106a7b89dbed51c28f8120a48b368b4:ipp

# cf. https://software.intel.com/en-us/articles/intel-itt-api-open-source
ITT_DESC=		Intel profiling API
ITT_CMAKE_BOOL=		WITH_ITT

NONFREE_DESC=		enable non free algorithms
NONFREE_CMAKE_BOOL=	OPENCV_ENABLE_NONFREE

QUIRC_DESC=		enable QR-code decoding
QUIRC_CMAKE_BOOL=	WITH_QUIRC

VA_DESC=		libva support
VA_LIB_DEPENDS=		libva.so:multimedia/libva
VA_CMAKE_BOOL=		WITH_VA

BLASLIB_DESC=		BLAS and LAPACK libraries

ATLAS_USES=		blaslapack:atlas
ATLAS_CMAKE_BOOL=	WITH_LAPACK

NETLIB_USES=		blaslapack:netlib
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas \
			liblapacke.so:math/lapacke
NETLIB_CMAKE_BOOL=	WITH_LAPACK
NETLIB_VARS=		LDFLAGS+=-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT} \
			LDFLAGS+=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so
NETLIB_CMAKE_ARGS=	-DCMAKE_INSTALL_RPATH=${LOCALBASE}/lib;${LOCALBASE}/lib/gcc${GCC_DEFAULT}
NETLIB_BUILD_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so:lang/gcc${GCC_DEFAULT}
NETLIB_RUN_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so:lang/gcc${GCC_DEFAULT}

OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_BUILD_DEPENDS=	${LOCALBASE}/include/cblas.h:math/cblas \
			${LOCALBASE}/include/lapacke.h:math/lapacke
OPENBLAS_CMAKE_BOOL=	WITH_LAPACK
OPENBLAS_VARS=		${NETLIB_VARS}
OPENBLAS_CMAKE_ARGS=	${NETLIB_CMAKE_ARGS}
OPENBLAS_BUILD_DEPENDS+=	${NETLIB_BUILD_DEPENDS}
OPENBLAS_RUN_DEPENDS=	${NETLIB_RUN_DEPENDS}

PERFORMANCE_DESC=	Performance enhancing libraries

CAROTENE_DESC=		NVidia carotene acceleration library for ARM platform
CAROTENE_CMAKE_BOOL=	WITH_CAROTENE

COINMP_DESC=		CoinMP support
COINMP_LIB_DEPENDS=	libClp.so:math/coinmp \
			libClpSolver.so:math/coinmp \
			libCoinUtils.so:math/coinmp
COINMP_CMAKE_BOOL=	WITH_CLP

EIGEN3_DESC=		Eigen 3 support
EIGEN3_USES=		eigen:3
EIGEN3_CMAKE_BOOL=	WITH_EIGEN

NEON_DESC=		enable NEON instructions (arm or aarch64)
NEON_CMAKE_BOOL=	ENABLE_NEON

OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_BUILD_DEPENDS=	opencl>=0:devel/opencl
OPENCL_RUN_DEPENDS=	opencl>=0:devel/opencl
OPENCL_CMAKE_BOOL=	WITH_OPENCL

OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_BOOL=	WITH_OPENMP
OPENMP_CXXFLAGS+=	-fopenmp

TBB_DESC=		Parallel processing support via TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb
TBB_CMAKE_BOOL=		WITH_TBB

VFPV3_DESC=		enable VFPv3-D32 instructions (arm or aarch64)
VFPV3_CMAKE_BOOL=	ENABLE_VFPV3

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

OPENEXR_LIB_DEPENDS=	libHalf.so:graphics/ilmbase \
			libIex-2_3.so:graphics/ilmbase \
			libIlmThread-2_3.so:graphics/ilmbase \
			libImath-2_3.so:graphics/ilmbase \
			libIlmImf.so:graphics/openexr
MFX_DESC=		Intel MediaSDK (aka Quick Sync Video)
MFX_LIB_DEPENDS=	libmfx.so:multimedia/intel-media-sdk \
			libva-drm.so:multimedia/libva
MFX_CONFIGURE_ENV=	MFX_HOME="${LOCALBASE}"
MFX_CMAKE_BOOL=		WITH_MFX

OPENEXR_CMAKE_BOOL=	WITH_OPENEXR

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL=		WITH_PNG

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	WITH_TIFF

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=	WITH_WEBP

HDR_DESC=		HDR support
HDR_CMAKE_BOOL=		WITH_IMGCODEC_HDR

SUNRASTER_DESC=		Sun raster image format support
SUNRASTER_CMAKE_BOOL=	WITH_IMGCODEC_SUNRASTER

PXM_DESC=		PNM (PBM, PGM, PPM) and PAM formats support
PXM_CMAKE_BOOL=		WITH_IMGCODEC_PXM

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

TOOLKITS_DESC=		GUI Toolkits and Visualization

GTK2_USES=		gnome
GTK2_USE=		GNOME=cairo,gdkpixbuf2,gtk20
GTK2_CMAKE_BOOL=	WITH_GTK WITH_GTK_2_X
GTK2_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libsz.so:science/szip \
			libfontconfig.so:x11-fonts/fontconfig \
			liblept.so:graphics/leptonica
GTK2_PREVENTS=		GTK3

OPENGL_DESC=		OpenGL (requires GTK2)
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu
OPENGL_CMAKE_BOOL=	WITH_OPENGL
OPENGL_LIB_DEPENDS=	${PORT_OPTIONS:MGTK2:C,.+,libgtkglext-x11-1.0.so:x11-toolkits/gtkglext,}
OPENGL_IMPLIES=		GTK2
OPENGL_PREVENTS=	GTK3

OGRE_DESC=		OGRE 3D engine support
OGRE_LIB_DEPENDS=	libOgreBites.so:graphics/ogre3d

GTK3_DESC=		GTK3 (disables OpenGL)
GTK3_USES=		gettext-runtime
GTK3_USE=		GNOME=cairo,glib20,gdkpixbuf2,gtk30
GTK3_CMAKE_BOOL=	WITH_GTK
GTK3_PREVENTS=		GTK2 OPENGL
GTK3_PREVENTS_DESC=	OpenGL is only usable with gtk2.

QT_DESC=		Qt GUI module
QT_USES=		qt:5
QT_USE=			QT=buildtools_build,concurrent,core,gui,opengl,qmake_build,testlib,widgets
QT_CMAKE_BOOL=		WITH_QT

VTK_DESC=		VTK library support and build viz module
VTK_USE=		xorg=x11,ice,sm,xext,xt
VTK_LIB_DEPENDS=	libvtksys-8.1.so:math/vtk8 \
			libfreetype.so:print/freetype2
VTK_CMAKE_BOOL=		WITH_VTK BUILD_opencv_viz
VTK_IMPLIES=		JPEG PNG TIFF

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

TESSERACT_DESC=			OCR engine (needed by contrib_text mod.)
TESSERACT_LIB_DEPENDS=		libtesseract.so:graphics/tesseract

TESTS_DESC=		Build and install tests
TESTS_CMAKE_BOOL=	BUILD_PERF_TESTS BUILD_TESTS INSTALL_TESTS

OCV_LIBDIR=		${LOCALBASE}/lib
.if defined(OCV_CORE)
.  for module in ${OCV_MODS} ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS} ${OCV_VTK_MODS}
CMAKE_OFF+=		BUILD_opencv_${module}
.  endfor

.elif defined(OCV_PYTHON)
_PYTHON_FEATURE_FLAVORS=	yes
CATEGORIES+=	python
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${OCV_LIBDIR}/libopencv_ml.so.${DISTVERSION}:graphics/opencv
USES+=		python
USE_PYTHON=	flavors
CMAKE_ON+=	BUILD_opencv_python${PYTHON_MAJOR_VER}
.  for module in apps java stitching superres videostab
CMAKE_OFF+=	BUILD_opencv_${module}
.  endfor
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}/modules/python${PYTHON_MAJOR_VER}
EXAMPLES_CMAKE_BOOL+=	INSTALL_PYTHON_EXAMPLES

.elif defined(OCV_JAVA)
CATEGORIES+=	java
BUILD_DEPENDS+=	ant:devel/apache-ant
USES+=		python:build
USE_JAVA=	yes
CMAKE_ON=	BUILD_opencv_java \
		BUILD_JAVA
.  for module in	apps js python2 python3 shape stitching superres ts \
		videostab viz
CMAKE_OFF+=	BUILD_opencv_${module}
.  endfor
CONFIGURE_ENV+=	JAVA_HOME="${JAVA_HOME}"
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}/modules/java

.elif defined(OCV_JS)
CMAKE_BOOL=	BUILD_opencv_js
# emscripten is not in the port. So, corresponding slave port does not exist.
.  for module in apps python java calib3d flann highgui imgcodecs ml photo \
		shape stitching superres ts videoio videostab viz
CMAKE_OFF+=	BUILD_opencv_${module}
.  endfor
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}/modules/js

.else
EXAMPLES_CMAKE_BOOL+=	INSTALL_C_EXAMPLES
# LIB_DEPENDS+=	libopencv_core.so.${DISTVERSION}:graphics/opencv${OCV_SUFFIX}-core
.  for module in ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS} ${OCV_JS_MODS}
CMAKE_OFF+=	BUILD_opencv_${module}
.  endfor
.endif

.if !defined(OCV_JAVA)
CMAKE_OFF+=	BUILD_JAVA
.endif


post-extract-IPP-on:
	@${MKDIR} ${CONFIGURE_WRKSRC}/3rdparty/ippicv
	(cd ${CONFIGURE_WRKSRC}/3rdparty/ippicv; \
		${GZCAT} ${IPP_DPATH}/ippicv/${IPPICVARC} | ${CPIO} -i)
.for f in iw_own.c iw_core.c
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		-e 's/memalign/aligned_alloc/' \
		${CONFIGURE_WRKSRC}/3rdparty/ippicv/ippicv_lnx/iw/src/${f}
.endfor

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


post-build-DOXYGEN-on:
.if !defined(OCV_SLAVE)
	${MAKE_CMD} -C ${BUILD_WRKSRC} doc/doxygen_cpp
	${MAKE_CMD} -C ${BUILD_WRKSRC} doc/doxygen
	${MAKE_CMD} -C ${BUILD_WRKSRC} opencv_docs
.elif defined(OCV_JAVA)
	${MAKE_CMD} -C ${BUILD_WRKSRC} doxygen_javadoc
.elif defined(OCV_PYTHON)
	${MAKE_CMD} -C ${BUILD_WRKSRC} doxygen_python
.endif


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

post-install-DOXYGEN-on:
.if !defined(OCV_SLAVE)
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type d -empty -delete
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} -ne 's|${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}
.endif

post-install-EXAMPLES-on:
.if defined(OCV_JAVA)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/java && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/java
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPP}
.  if ${ARCH} == amd64
LICENSE+=		ISSL
LICENSE_COMB=		multi
LICENSE_NAME_ISSL=	Intel Simplified Software License (Version April 2018)
LICENSE_PERMS_ISSL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_ISSL=	${CONFIGURE_WRKSRC}/3rdparty/ippicv/ippicv_lnx/EULA.txt

IPPICVARC=		ippicv_2019_lnx_intel64_general_20180723.tgz
CMAKE_ARGS+=		-DWITH_IPP:BOOL=ON \
			-DBUILD_IPP_IW:BOOL=ON
PLIST_SUB+=		IPPICV=""

.  elif ${ARCH} == i386
IPPICVARC=		ippicv_2019_lnx_ia32_general_20180723.tgz
# IPP on i386 cannot be used with dynamic libraries.
PLIST_SUB+=		IPPICV="@comment "
.  else
PLIST_SUB+=		IPPICV="@comment "
.  endif
.else
PLIST_SUB+=		IPPICV="@comment "
.endif
IPP_DPATH=	${WRKDIR}/opencv_3rdparty-${IPP_GH_TAGNAME:S/:ipp//}

.if ${PORT_OPTIONS:MOPENMP} && ${COMPILER_TYPE} == clang
LIB_DEPENDS+=	libomp.so:devel/openmp
.endif

.if ${PORT_OPTIONS:MEXTRA_MODULES} && !defined(OCV_CORE)
CMAKE_ARGS+=	-DOPENCV_EXTRA_MODULES_PATH=${WRKDIR}/opencv_contrib-${PORTVERSION}/modules
.endif

.include <bsd.port.post.mk>
