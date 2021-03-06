# $FreeBSD$

PORTNAME=	cups-cloud-print
PORTVERSION=	20160502
PORTREVISION=	1
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print using Google Cloud Print

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Google Cloud Print has been shut down by Google as of December 31, 2020
EXPIRATION_DATE=2021-02-28

BUILD_DEPENDS=	cups-config:print/cups
RUN_DEPENDS=	cancel:print/cups \
		bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycups>=0:print/py-pycups@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	simoncadman
GH_PROJECT=	CUPS-Cloud-Print

USES=		gmake python:3.6+ shebangfix
SHEBANG_FILES=	testing/*.sh
GNU_CONFIGURE=	yes
MAKE_ARGS=	NOPERMS=1
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/cloudprint-cups
DOCSDIR=	${PREFIX}/share/doc/cloudprint-cups

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/README.md/s|^|#| ; \
		 /COPYING/s|^|#|' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
