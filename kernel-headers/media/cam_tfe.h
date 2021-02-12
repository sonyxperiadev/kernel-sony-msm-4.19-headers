/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __UAPI_CAM_TFE_H__
#define __UAPI_CAM_TFE_H__
#include "cam_defs.h"
#include "cam_isp_tfe.h"
#include "cam_cpas.h"
#define CAM_ISP_TFE_DEV_NAME "cam-isp"
#define CAM_ISP_TFE_HW_BASE 0
#define CAM_ISP_TFE_HW_CSID 1
#define CAM_ISP_TFE_HW_TFE 2
#define CAM_ISP_TFE_HW_MAX 3
#define CAM_ISP_TFE_PATTERN_BAYER_RGRGRG 0
#define CAM_ISP_TFE_PATTERN_BAYER_GRGRGR 1
#define CAM_ISP_TFE_PATTERN_BAYER_BGBGBG 2
#define CAM_ISP_TFE_PATTERN_BAYER_GBGBGB 3
#define CAM_ISP_TFE_PATTERN_YUV_YCBYCR 4
#define CAM_ISP_TFE_PATTERN_YUV_YCRYCB 5
#define CAM_ISP_TFE_PATTERN_YUV_CBYCRY 6
#define CAM_ISP_TFE_PATTERN_YUV_CRYCBY 7
#define CAM_ISP_TFE_PATTERN_MAX 8
#define CAM_ISP_TFE_IN_RES_USAGE_SINGLE 0
#define CAM_ISP_TFE_IN_RES_USAGE_DUAL 1
#define CAM_ISP_TFE_IN_RES_USAGE_MAX 2
#define CAM_ISP_TFE_RES_ID_PORT 0
#define CAM_ISP_TFE_RES_ID_MAX 1
#define CAM_ISP_TFE_IN_LANE_TYPE_DPHY 0
#define CAM_ISP_TFE_IN_LANE_TYPE_CPHY 1
#define CAM_ISP_TFE_IN_LANE_TYPE_MAX 2
#define CAM_ISP_TFE_PACKET_OP_BASE 0
#define CAM_ISP_TFE_PACKET_INIT_DEV 1
#define CAM_ISP_TFE_PACKET_CONFIG_DEV 2
#define CAM_ISP_TFE_PACKET_OP_MAX 3
#define CAM_ISP_TFE_PACKET_META_BASE 0
#define CAM_ISP_TFE_PACKET_META_LEFT 1
#define CAM_ISP_TFE_PACKET_META_RIGHT 2
#define CAM_ISP_TFE_PACKET_META_COMMON 3
#define CAM_ISP_TFE_PACKET_META_DUAL_CONFIG 4
#define CAM_ISP_TFE_PACKET_META_GENERIC_BLOB_COMMON 5
#define CAM_ISP_TFE_PACKET_META_REG_DUMP_PER_REQUEST 6
#define CAM_ISP_TFE_PACKET_META_REG_DUMP_ON_FLUSH 7
#define CAM_ISP_TFE_PACKET_META_REG_DUMP_ON_ERROR 8
#define CAM_ISP_TFE_GENERIC_BLOB_TYPE_HFR_CONFIG 0
#define CAM_ISP_TFE_GENERIC_BLOB_TYPE_CLOCK_CONFIG 1
#define CAM_ISP_TFE_GENERIC_BLOB_TYPE_BW_CONFIG_V2 2
#define CAM_ISP_TFE_GENERIC_BLOB_TYPE_CSID_CLOCK_CONFIG 3
#define CAM_ISP_TFE_DSP_MODE_NONE 0
#define CAM_ISP_TFE_DSP_MODE_ONE_WAY 1
#define CAM_ISP_TFE_DSP_MODE_ROUND 2
#define CAM_ISP_TFE_USAGE_INVALID 0
#define CAM_ISP_TFE_USAGE_LEFT_PX 1
#define CAM_ISP_TFE_USAGE_RIGHT_PX 2
#define CAM_ISP_TFE_USAGE_RDI 3
#define CAM_ISP_TFE_WM_FRAME_BASED_MODE 0
#define CAM_ISP_TFE_WM_LINE_BASED_MODE 1
#define CAM_ISP_TFE_WM_INDEX_BASED_MODE 2
struct cam_isp_tfe_dev_cap_info {
  uint32_t hw_type;
  uint32_t reserved;
  struct cam_hw_version hw_version;
};
struct cam_isp_tfe_query_cap_cmd {
  struct cam_iommu_handle device_iommu;
  struct cam_iommu_handle cdm_iommu;
  int32_t num_dev;
  uint32_t reserved;
  struct cam_isp_tfe_dev_cap_info dev_caps[CAM_ISP_TFE_HW_MAX];
};
struct cam_isp_tfe_out_port_info {
  uint32_t res_id;
  uint32_t format;
  uint32_t width;
  uint32_t height;
  uint32_t stride;
  uint32_t comp_grp_id;
  uint32_t secure_mode;
  uint32_t wm_mode;
  uint32_t reserved;
};
struct cam_isp_tfe_in_port_info {
  uint32_t res_id;
  uint32_t lane_type;
  uint32_t lane_num;
  uint32_t lane_cfg;
  uint32_t vc;
  uint32_t dt;
  uint32_t format;
  uint32_t pix_pattern;
  uint32_t usage_type;
  uint32_t left_start;
  uint32_t left_end;
  uint32_t left_width;
  uint32_t right_start;
  uint32_t right_end;
  uint32_t right_width;
  uint32_t line_start;
  uint32_t line_end;
  uint32_t height;
  uint32_t batch_size;
  uint32_t dsp_mode;
  uint32_t sensor_width;
  uint32_t sensor_height;
  uint32_t sensor_hbi;
  uint32_t sensor_vbi;
  uint32_t sensor_fps;
  uint32_t init_frame_drop;
  uint32_t num_out_res;
  struct cam_isp_tfe_out_port_info data[1];
};
struct cam_isp_tfe_resource {
  uint32_t resource_id;
  uint32_t length;
  uint32_t handle_type;
  uint32_t reserved;
  uint64_t res_hdl;
};
struct cam_isp_tfe_port_hfr_config {
  uint32_t resource_type;
  uint32_t subsample_pattern;
  uint32_t subsample_period;
  uint32_t framedrop_pattern;
  uint32_t framedrop_period;
  uint32_t reserved;
} __attribute__((packed));
struct cam_isp_tfe_resource_hfr_config {
  uint32_t num_ports;
  uint32_t reserved;
  struct cam_isp_tfe_port_hfr_config port_hfr_config[1];
} __attribute__((packed));
struct cam_isp_tfe_dual_stripe_config {
  uint32_t offset;
  uint32_t width;
  uint32_t port_id;
  uint32_t reserved;
};
struct cam_isp_tfe_dual_config {
  uint32_t num_ports;
  uint32_t reserved;
  struct cam_isp_tfe_dual_stripe_config stripes[1];
} __attribute__((packed));
struct cam_isp_tfe_clock_config {
  uint32_t usage_type;
  uint32_t num_rdi;
  uint64_t left_pix_hz;
  uint64_t right_pix_hz;
  uint64_t rdi_hz[1];
} __attribute__((packed));
struct cam_isp_tfe_csid_clock_config {
  uint64_t csid_clock;
  uint64_t phy_clock;
} __attribute__((packed));
struct cam_isp_tfe_bw_config_v2 {
  uint32_t usage_type;
  uint32_t num_paths;
  struct cam_axi_per_path_bw_vote axi_path[1];
} __attribute__((packed));
struct cam_isp_tfe_acquire_hw_info {
  uint16_t common_info_version;
  uint16_t common_info_size;
  uint32_t common_info_offset;
  uint32_t num_inputs;
  uint32_t input_info_version;
  uint32_t input_info_size;
  uint32_t input_info_offset;
  uint64_t data;
};
#define CAM_TFE_ACQUIRE_COMMON_VER0 0x1000
#define CAM_TFE_ACQUIRE_COMMON_SIZE_VER0 0x0
#define CAM_TFE_ACQUIRE_INPUT_VER0 0x2000
#define CAM_TFE_ACQUIRE_INPUT_SIZE_VER0 sizeof(struct cam_isp_tfe_in_port_info)
#define CAM_TFE_ACQUIRE_OUT_VER0 0x3000
#define CAM_TFE_ACQUIRE_OUT_SIZE_VER0 sizeof(struct cam_isp_tfe_out_port_info)
#endif
