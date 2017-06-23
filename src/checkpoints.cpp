// Copyright (c) 2009-2017 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "proofs.h"
#include "txdb.h"
#include "main.h"
#include "uint256.h"

static const int nCheckpointSpan = 5000;

namespace Checkpoints
{
	typedef std::map<int, uint256> MapCheckpoints;
    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (0,     Params().HashGenesisBlock())
		(1000, uint256("00000007075466184507ebe0eccbcfeceede1b9785c344f0ba7315d394bd6211"))
		(2000, uint256("00000002e2095ce7e3ab1bd94218dfafb792147a9fb3e4f2136882cfe5fe0808"))
		(5000, uint256("000000358d593954acc6a8167422d5b599e3555d400bf7f02cefb3b44f0b584b"))
		(179600, uint256("043e02f408ee9e43e600e476ea33cc80241666e9e3811abdf261825b1d1adaa0"))
/*        (1,     uint256("0x000000ed2f68cd6c7935831cc1d473da7c6decdb87e8b5dba0afff0b00002690") ) // Premine
        (10,    uint256("0x00000032f5a96d31d74b380c0336445baccb73a01bdbedec868283019bad7016") )  // Confirmation of Premine
        (22,    uint256("0x00000002e04f91402d78b84433ec744aacac5c40952b918fe09a7d623ac33967") )
        (32,    uint256("0x0000001880da8fd09cc6f5e93315135fe686eb49f9054c807fa810d56ebb013b") )
        (35,    uint256("0x0000000af6204fd43bb9cafea1dd192c245979d4dd7bde19efb92f633589ade5") )
        (45,    uint256("0x00000006d6b9e9fba4dee10bc63ca7ea764c80c2b9c4fa6ddedb944eb288a371") )
*/
		;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        if (checkpoints.empty())
            return 0;
        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // Automatically select a suitable sync-checkpoint 
    const CBlockIndex* AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && pindex->nHeight + nCheckpointSpan > pindexBest->nHeight)
            pindex = pindex->pprev;
        return pindex;
    }

    // Check against synchronized checkpoint
    bool CheckSync(int nHeight)
    {
        const CBlockIndex* pindexSync = AutoSelectSyncCheckpoint();
        if (nHeight <= pindexSync->nHeight){
            return false;
        }
        return true;
    }
}
