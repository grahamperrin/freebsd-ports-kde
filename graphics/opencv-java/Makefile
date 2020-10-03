# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-${_OCV_PACKAGE}
CATEGORIES=	graphics java

COMMENT=	OpenCV Java library

_OCV_PACKAGE=	java

MASTERDIR=	${.CURDIR:H}/opencv
PLIST=		${.CURDIR}/pkg-plist

PLIST_SUB+=	OCV_VER=${DISTVERSION:S|.||g}

.include "${MASTERDIR}/Makefile"
