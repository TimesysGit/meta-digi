# Copyright (C) 2011 Freescale Semiconductor
# Copyright (C) 2012 Digi international
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = "Gstreamer freescale plugins"
LICENSE = "GPLv2 & LGPLv2 & LGPLv2.1"
SECTION = "multimedia"
DEPENDS = "gstreamer gst-plugins-base fsl-mm-codeclib imx-lib"
RDEPENDS_${PN} = "fsl-mm-codeclib"
INC_PR = "r5"

LIC_FILES_CHKSUM = "file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
                    file://COPYING-LGPL-2;md5=5f30f0716dfdd0d91eb439ebec522ec2 \
                    file://COPYING-LGPL-2.1;md5=fbc093901857fcd118f065f900982c24"

SRC_URI = "${DIGI_LOG_MIRROR}/${PN}-${PV}.tar.gz \
          "

inherit autotools pkgconfig

# Todo add a mechanism to map posible build targets
INCLUDE_DIR = "-I${STAGING_KERNEL_DIR}/include"
EXTRA_OEMAKE = "INCLUDES=${INCLUDE_DIR}"
EXTRA_OECONF = "PLATFORM=MX51 --disable-valgrind --disable-examples --disable-debug"

PACKAGES += "${PN}-libmfwsconf ${PN}-libgplaycore \
             ${PN}-libme ${PN}-libgstbufmeta ${PN}-libmfwba \
             ${PN}-libfwvss ${PN}-gplay"

FILES_${PN} = "${libdir}/gstreamer-0.10/*.so ${datadir}"
FILES_${PN}-dbg += "${libdir}/gstreamer-0.10/.debug"
FILES_${PN}-dev += "${libdir}/gstreamer-0.10/*.la"
FILES_${PN}-staticdev += "${libdir}/gstreamer-0.10/*.a"

FILES_${PN}-gplay = "${bindir}/gplay"
FILES_${PN}-libmfwsconf = "${libdir}/libmfwsconf${SOLIBS}"
FILES_${PN}-libgplaycore = "${libdir}/libgplaycore${SOLIBS}"
FILES_${PN}-libme = "${libdir}/libme${SOLIBS}"
FILES_${PN}-libgstbufmeta = "${libdir}/libgstbufmeta${SOLIBS}"
FILES_${PN}-libmfwba =  "${libdir}/libmfwba${SOLIBS}"
FILES_${PN}-libfwvss = "${libdir}/libmfwvss${SOLIBS}"