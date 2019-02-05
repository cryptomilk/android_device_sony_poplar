/*
 * Copyright (C) 2008 The Android Open Source Project
 * Copyright (C) 2014 The CyanogenMod Project
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>
#include <fstream>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "vendor_init.h"
#include "property_service.h"

#define LTALABEL_PATH "/dev/block/bootdevice/by-name/LTALabel"

using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void target_load_properties()
{
    std::string model;
    if (std::ifstream file = std::ifstream(LTALABEL_PATH, std::ios::binary)) {
        std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        size_t offset = str.find("Model: ");

        if (offset != std::string::npos) {
            model = str.substr(offset + 7, 5);
        }
    }

    if (model == "G8342") {
            property_set("persist.multisim.config", "dsds");
            property_set("persist.radio.multisim.config", "dsds");
            property_set("ro.telephony.default_network", "10,1");
            property_set("ro.semc.product.model", "G8342");
            property_override_dual("ro.product.model", "ro.vendor.product.model", "G8342");
            property_override_dual("ro.product.name", "ro.vendor.product.name", "poplar_dsds");
            property_override_dual("ro.product.device", "ro.vendor.product.device", "poplar_dsds");
            property_override("ro.build.description", "Sony/poplar_dsds/poplar_dsds:9/YOSHINO-2.2.0-190107-1901/1:user/dev-keys");
            property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "Sony/poplar_dsds/poplar_dsds:9/YOSHINO-2.2.0-190107-1901/1:user/dev-keys");
        } else {
            property_set("ro.telephony.default_network", "10");
            property_set("ro.semc.product.model", "G8341");
            property_override_dual("ro.product.model", "ro.vendor.product.model", "G8341");
            property_override_dual("ro.product.name", "ro.vendor.product.name", "poplar");
            property_override_dual("ro.product.device", "ro.vendor.product.device", "poplar");
            property_override("ro.build.description", "G8341-user 8.0.0 47.1.A.12.205 1908034680 release-keys");
            property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "Sony/G8341/G8341:8.0.0/47.1.A.12.205/1908034680:user/release-keys");
        }
}
