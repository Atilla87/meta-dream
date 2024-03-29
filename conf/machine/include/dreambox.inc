# dreambox.inc
# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

OPTIONAL_BSP_PACKAGES += "dreambox-buildimage"

EXTRA_IMAGEDEPENDS += "dreambox-secondstage-${MACHINE}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "dreambox-dvb-modules-${MACHINE}"

KERNEL_MODULE_AUTOLOAD += "xfs"

MACHINE_EXTRA_RRECOMMENDS += "\
	gstreamer1.0-plugin-dvbmediasink \
	ntfs-3g \
	kernel-module-cifs \
	kernel-module-hmac \
	kernel-module-md4 \
	kernel-module-ecb \
	dreambox-boot-progress \
	"

MACHINE_EXTRA_RRECOMMENDS_append_dm8000 += "\
	enigma2-plugin-drivers-network-ath5k \
	"

MACHINE_FEATURES += "alsa usbhost 3dtv switchoff dreambox"
# Add "dreambox" override for recipes
MACHINEOVERRIDES .= ":dreambox"

PREFERRED_PROVIDER_virtual/bootloader = "dreambox-secondstage-${MACHINE}"
PREFERRED_PROVIDER_virtual/kernel = "linux-dreambox"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "dreambox-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "dreambox-blindscan-utils"

PREFERRED_VERSION_rt8812au = "4.3.14"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_OUTPUT_DIR = "."
KERNEL_CONSOLE = "${@bb.utils.contains('MACHINE_FEATURES', 'usbconsole', 'ttyS0,115200', 'null', d)}"

DREAMBOX_BUILDIMAGE = "buildimage --arch ${MACHINE} ${EXTRA_BUILDCMD} \
	--erase-block-size ${DREAMBOX_ERASE_BLOCK_SIZE} \
	--flash-size ${DREAMBOX_FLASH_SIZE} \
	--sector-size ${DREAMBOX_SECTOR_SIZE}"
