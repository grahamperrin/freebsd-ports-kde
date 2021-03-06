# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osm2pgsql
PORTVERSION=	1.4.0
CATEGORIES=	converters geography

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert OSM XML data to PostgreSQL database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt
BUILD_DEPENDS=	${LOCALBASE}/include/osmium/version.hpp:astro/libosmium \
		${LOCALBASE}/include/protozero/version.hpp:devel/protozero

USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap

USES=		cmake compiler:c++11-lang pgsql
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git \
		EXTERNAL_LIBOSMIUM \
		EXTERNAL_PROTOZERO \
		EXTERNAL_FMT

PLIST_FILES=	bin/osm2pgsql \
		share/man/man1/osm2pgsql.1.gz

PORTDOCS=	AUTHORS CONTRIBUTING.md README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS LUAJIT TEST

LUAJIT_DESC=		Build with LuaJIT support
LUAJIT_CMAKE_BOOL=	WITH_LUAJIT
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_USES_OFF=	lua:53
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|find_package(Lua |&${LUA_VER} EXACT |' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
