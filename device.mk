### PLATFORM
$(call inherit-product, device/sony/yoshino/platform.mk)
### PROPRIETARY VENDOR FILES
$(call inherit-product, vendor/sony/poplar/poplar-vendor.mk)

### DALVIK/HWUI
$(call inherit-product, frameworks/native/build/phone-xhdpi-2048-dalvik-heap.mk)
$(call inherit-product, frameworks/native/build/phone-xxhdpi-2048-hwui-memory.mk)

DEVICE_PATH := device/sony/poplar

include $(DEVICE_PATH)/device/*.mk
