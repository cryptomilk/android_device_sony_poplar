#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

### INHERIT FROM YOSHIRO
include device/sony/yoshino/BoardConfigPlatform.mk

DEVICE_PATH := device/sony/poplar

PRODUCT_PLATFORM := yoshino

### BOOTLOADER
TARGET_BOOTLOADER_BOARD_NAME := G8441

### KERNEL
TARGET_KERNEL_CONFIG := lineage-msm8998-yoshino-poplar_defconfig

BOARD_KERNEL_CMDLINE += androidboot.hardware=poplar

### PARTITIONS
# See also /proc/partitions on the device
BOARD_BOOTIMAGE_PARTITION_SIZE := 67108864
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 67108864
BOARD_CACHEIMAGE_PARTITION_SIZE := 398458880
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 5242880000
BOARD_FLASH_BLOCK_SIZE := 131072 # (BOARD_KERNEL_PAGESIZE * 64)
# Reserve space for data encryption (55743832064-32768)
BOARD_USERDATAIMAGE_PARTITION_SIZE := 55743799296
