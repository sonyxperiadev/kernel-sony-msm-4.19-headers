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
#ifndef _UAPI_SMCINVOKE_H_
#define _UAPI_SMCINVOKE_H_
#include <linux/types.h>
#include <linux/ioctl.h>
#define SMCINVOKE_USERSPACE_OBJ_NULL - 1
struct smcinvoke_buf {
  uint64_t addr;
  uint64_t size;
};
struct smcinvoke_obj {
  int64_t fd;
  int32_t cb_server_fd;
  int32_t reserved;
};
union smcinvoke_arg {
  struct smcinvoke_buf b;
  struct smcinvoke_obj o;
};
struct smcinvoke_cmd_req {
  uint32_t op;
  uint32_t counts;
  int32_t result;
  uint32_t argsize;
  uint64_t args;
};
struct smcinvoke_accept {
  uint32_t has_resp;
  uint32_t txn_id;
  int32_t result;
  int32_t cbobj_id;
  uint32_t op;
  uint32_t counts;
  int32_t reserved;
  uint32_t argsize;
  uint64_t buf_len;
  uint64_t buf_addr;
};
struct smcinvoke_server {
  uint32_t cb_buf_size;
};
#define SMCINVOKE_IOC_MAGIC 0x98
#define SMCINVOKE_IOCTL_INVOKE_REQ _IOWR(SMCINVOKE_IOC_MAGIC, 1, struct smcinvoke_cmd_req)
#define SMCINVOKE_IOCTL_ACCEPT_REQ _IOWR(SMCINVOKE_IOC_MAGIC, 2, struct smcinvoke_accept)
#define SMCINVOKE_IOCTL_SERVER_REQ _IOWR(SMCINVOKE_IOC_MAGIC, 3, struct smcinvoke_server)
#define SMCINVOKE_IOCTL_ACK_LOCAL_OBJ _IOWR(SMCINVOKE_IOC_MAGIC, 4, int32_t)
#endif
