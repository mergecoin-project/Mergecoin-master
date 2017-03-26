// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ION_POW_H
#define ION_POW_H

#include <stdint.h>

#include "amount.h"
#include <sync.h>
#include <util.h>
#include <stdint.h>

class CBlockIndex;
class uint256;

static const int nTargetSpacing = 64;

/** Determine Coinbase Maturity (generally not a good idea - done so to increase speed) */
int DetermineCoinbaseMaturity();
/** Calculate difficulty using retarget algorithm by maintaining target */
unsigned int GetNextTargetRequired(const CBlockIndex* pindexLast, bool fProofOfStake);
/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckProofOfWork(uint256 hash, unsigned int nBits);
/** Determine Block Reward for Proof Of Work **/
int64_t GetCoinbaseValue(int nHeight, CAmount nFees);
/** Determine Block Reward for Proof Of Stake **/
int64_t GetCoinstakeValue(int64_t nCoinAge, CAmount nFees, int nHeight);

#endif // BITCOIN_POW_H
