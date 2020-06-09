/*
 * key.h
 *
 *  Created on: 2016年7月27日
 *      Author: zhangpei
 */

#ifndef KEY_H_
#define KEY_H_

#define BOOL int
#define TRUE 1
#define FALSE 0

#include <stdint.h>

// @desc 根据包名、tmsi和时间戳获取加/解密key
// @param key：生成的加密key，长度固定为16字节
// @param bundleID：应用的包名
// @param tmsi：服务器生成的tmsi
// @param timestamp：时间戳
void ym_get_key(uint8_t *key, const uint8_t *bundleID, const uint8_t *tmsi, uint64_t timestamp);

// @desc 计算字符串的哈希值
// @param str：待计算的字符串
uint32_t ym_hash_code(const uint8_t *str);

// @desc 判断系统是否为大端模式
BOOL is_big_endian(void);

// @desc 更改数据的void大小端模式
// @param value：待更改的数据
uint64_t ym_swich_endian(uint64_t value);

#endif /* KEY_H_ */
