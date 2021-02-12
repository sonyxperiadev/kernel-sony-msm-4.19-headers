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
#ifndef __UAPI_OPE_H__
#define __UAPI_OPE_H__
#include "cam_defs.h"
#include "cam_cpas.h"
#define OPE_DEV_NAME_SIZE 128
#define OPE_HW_TYPE_OPE 0x1
#define OPE_HW_TYPE_OPE_CDM 0x2
#define OPE_HW_TYPE_MAX 0x3
#define OPE_DEV_TYPE_OPE_RT 0x1
#define OPE_DEV_TYPE_OPE_NRT 0x2
#define OPE_DEV_TYPE_OPE_SEMI_RT 0x3
#define OPE_DEV_TYPE_MAX 0x4
#define OPE_IN_RES_FULL 0x1
#define OPE_IN_RES_MAX OPE_IN_RES_FULL
#define OPE_OUT_RES_VIDEO 0x1
#define OPE_OUT_RES_DISP 0x2
#define OPE_OUT_RES_ARGB 0x3
#define OPE_OUT_RES_STATS_RS 0x4
#define OPE_OUT_RES_STATS_IHIST 0x5
#define OPE_OUT_RES_STATS_LTM 0x6
#define OPE_OUT_RES_MAX OPE_OUT_RES_STATS_LTM
#define OPE_OPCODE_CONFIG 0x1
#define OPE_CMD_BUF_SCOPE_BATCH 0x1
#define OPE_CMD_BUF_SCOPE_FRAME 0x2
#define OPE_CMD_BUF_SCOPE_PASS 0x3
#define OPE_CMD_BUF_SCOPE_STRIPE 0x4
#define OPE_CMD_BUF_TYPE_DIRECT 0x1
#define OPE_CMD_BUF_TYPE_INDIRECT 0x2
#define OPE_CMD_BUF_UMD 0x1
#define OPE_CMD_BUF_KMD 0x2
#define OPE_CMD_BUF_DEBUG 0x3
#define OPE_CMD_BUF_SINGLE_BUFFERED 0x1
#define OPE_CMD_BUF_DOUBLE_BUFFERED 0x2
#define OPE_CMD_META_GENERIC_BLOB 0x1
#define OPE_CMD_GENERIC_BLOB_CLK_V2 0x1
#define OPE_STRIPE_FULL 0x0
#define OPE_STRIPE_LEFT 0x1
#define OPE_STRIPE_RIGHT 0x2
#define OPE_STRIPE_MIDDLE 0x3
#define OPE_MAX_CMD_BUFS 64
#define OPE_MAX_IO_BUFS (OPE_OUT_RES_MAX + OPE_IN_RES_MAX)
#define OPE_MAX_PASS 1
#define OPE_MAX_PLANES 2
#define OPE_MAX_STRIPES 48
#define OPE_MAX_BATCH_SIZE 16
struct ope_stripe_info {
  uint32_t offset;
  uint32_t x_init;
  uint32_t stripe_location;
  uint32_t width;
  uint32_t height;
  uint32_t disable_bus;
  uint32_t reserved;
};
struct ope_io_buf_info {
  uint32_t direction;
  uint32_t resource_type;
  uint32_t num_planes;
  uint32_t reserved;
  uint32_t num_stripes[OPE_MAX_PLANES];
  uint32_t mem_handle[OPE_MAX_PLANES];
  uint32_t plane_offset[OPE_MAX_PLANES];
  uint32_t length[OPE_MAX_PLANES];
  uint32_t plane_stride[OPE_MAX_PLANES];
  uint32_t height[OPE_MAX_PLANES];
  uint32_t format;
  uint32_t fence;
  struct ope_stripe_info stripe_info[OPE_MAX_PLANES][OPE_MAX_STRIPES];
};
struct ope_frame_set {
  uint32_t num_io_bufs;
  uint32_t reserved;
  struct ope_io_buf_info io_buf[OPE_MAX_IO_BUFS];
};
struct ope_cmd_buf_info {
  uint32_t mem_handle;
  uint32_t offset;
  uint32_t size;
  uint32_t length;
  uint32_t cmd_buf_scope;
  uint32_t type;
  uint32_t cmd_buf_usage;
  uint32_t cmd_buf_buffered;
  uint32_t stripe_idx;
  uint32_t cmd_buf_pass_idx;
  uint32_t prefetch_disable;
};
struct ope_frame_process {
  uint32_t num_cmd_bufs[OPE_MAX_BATCH_SIZE];
  uint32_t batch_size;
  struct ope_cmd_buf_info cmd_buf[OPE_MAX_BATCH_SIZE][OPE_MAX_CMD_BUFS];
  struct ope_frame_set frame_set[OPE_MAX_BATCH_SIZE];
};
struct ope_clk_bw_request_v2 {
  uint64_t budget_ns;
  uint32_t frame_cycles;
  uint32_t rt_flag;
  uint32_t reserved;
  uint32_t num_paths;
  struct cam_axi_per_path_bw_vote axi_path[1];
};
struct ope_hw_ver {
  uint32_t hw_type;
  uint32_t reserved;
  struct cam_hw_version hw_ver;
};
struct ope_query_cap_cmd {
  struct cam_iommu_handle dev_iommu_handle;
  struct cam_iommu_handle cdm_iommu_handle;
  uint32_t num_ope;
  uint32_t reserved;
  struct ope_hw_ver hw_ver[OPE_DEV_TYPE_MAX];
};
struct ope_out_res_info {
  uint32_t res_id;
  uint32_t format;
  uint32_t width;
  uint32_t height;
  uint32_t alignment;
  uint32_t packer_format;
  uint32_t subsample_period;
  uint32_t subsample_pattern;
  uint32_t pixel_pattern;
  uint32_t reserved;
};
struct ope_in_res_info {
  uint32_t res_id;
  uint32_t format;
  uint32_t width;
  uint32_t height;
  uint32_t pixel_pattern;
  uint32_t alignment;
  uint32_t unpacker_format;
  uint32_t max_stripe_size;
  uint32_t fps;
  uint32_t reserved;
};
struct ope_acquire_dev_info {
  uint32_t hw_type;
  uint32_t dev_type;
  char dev_name[OPE_DEV_NAME_SIZE];
  uint32_t nrt_stripes_for_arb;
  uint32_t secure_mode;
  uint32_t batch_size;
  uint32_t num_in_res;
  struct ope_in_res_info in_res[OPE_IN_RES_MAX];
  uint32_t num_out_res;
  uint32_t reserved;
  struct ope_out_res_info out_res[OPE_OUT_RES_MAX];
} __attribute__((__packed__));
#endif
