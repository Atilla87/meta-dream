SRC_URI[dreamone.md5sum] = "46ec16659c46a6bda2d3bcdf56e39600"
SRC_URI[dreamone.sha256sum] = "6ce9cb641a01914c34b14018dd5f7b8a9d73e1b374cb9969c624ea2a920ad45a"

require dreambox-dvb-modules-meson.inc

SRC_URI += "file://LICENSE-CLOSE"

do_license() {
	mv ${WORKDIR}/LICENSE-CLOSE ${B}/LICENSE-CLOSE
}

addtask do_license before do_populate_lic after do_unpack

COMPATIBLE_MACHINE = "^(dreamone)$"
