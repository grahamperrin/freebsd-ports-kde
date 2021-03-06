# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	cdcollect
PORTVERSION=	0.6.0
PORTREVISION=	9
CATEGORIES=	misc gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple CD catalog for GNOME

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Unmaintained and dead upstream (12+ years) depends on \
		deprecated libraries as www/gtkhtml3.

EXPIRATION_DATE=2021-02-12

BUILD_DEPENDS=	sqlite3>=3.0:databases/sqlite3
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext gmake gnome localbase mono pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack libgnome gnomesharp20
GCONF_SCHEMAS=	cdcollect.schemas

GNU_CONFIGURE=	yes

NO_ARCH=	yes

post-extract:
	${REINPLACE_CMD} -e 's,SqliteClient,Sqlite,' \
	    ${WRKSRC}/src/Makefile.in \
	    ${WRKSRC}/src/CDIcon.cs \
	    ${WRKSRC}/src/CDItem.cs \
	    ${WRKSRC}/src/CompPluginWindow.cs \
	    ${WRKSRC}/src/DBsql.cs

.include <bsd.port.mk>
