/*
 * crypt.h
 *
 *  Created on: 2016年7月27日
 *      Author: zhangpei
 */

#ifndef CRYPT_H_
#define CRYPT_H_

#include <stdint.h>

// @desc 加密数据
// @param out：输出的加密结果
// @param in：待加密的数据
// @param len：待加密数据的长度（必须为16的倍数）
// @param key：加密密钥
void ym_encrypt(uint8_t *out, uint8_t *in, uint32_t len, uint8_t *key);

// @desc 解密数据
// @param out：输出的解密结果
// @param in：待解密的数据
// @param len：待解密数据的长度（必须为16的倍数）
// @param key：解密密钥
void ym_decrypt(uint8_t *out, uint8_t *in, uint32_t len, uint8_t *key);

// @desc 计算待加密数据的长度（将待加密数据的长度设置为16的倍数）
// @param len：数据的原始长度
uint32_t compute_len(uint32_t len);

#endif /* CRYPT_H_ */
