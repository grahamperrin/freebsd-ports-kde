# $FreeBSD$

PORTNAME=	gbrainy
DISTVERSION=	2.4.3
PORTEPOCH=	2
CATEGORIES=	games
MASTER_SITES=	https://gent.softcatala.org/jmas/gbrainy/

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Brain teaser game and trainer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mautil:devel/mono-addins \
		gtk-sharp30>0:x11-toolkits/gtk-sharp30 \
		itstool:textproc/itstool
RUN_DEPENDS=	mautil:devel/mono-addins \
		bash:shells/bash

USES=		gettext gmake gnome mono pathfix pkgconfig shebangfix
USE_GNOME=	gtksharp20 gnomesharp20 intltool

SHEBANG_FILES=	src/Clients/Classical/gbrainy.in

GNU_CONFIGURE=	yes

MAKE_ENV+=	MONO_REGISTRY_PATH=${WRKDIR}

INSTALLS_ICONS=	yes

.include <bsd.port.mk>
