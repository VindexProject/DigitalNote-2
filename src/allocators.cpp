// Copyright (c) 2009-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "compat.h"

#include "allocators.h"

LockedPageManager* LockedPageManager::_instance = NULL;
boost::once_flag LockedPageManager::init_flag = BOOST_ONCE_INIT;

/** Determine system page size in bytes */
static inline size_t GetSystemPageSize()
{
    size_t page_size;
	
#if defined(WIN32)
    SYSTEM_INFO sSysInfo;
    GetSystemInfo(&sSysInfo);
    page_size = sSysInfo.dwPageSize;
#elif defined(PAGESIZE) // defined in limits.h
    page_size = PAGESIZE;
#else // assume some POSIX OS
    page_size = sysconf(_SC_PAGESIZE);
#endif

    return page_size;
}

bool MemoryPageLocker::Lock(const void *addr, size_t len)
{
#ifdef WIN32
    return VirtualLock(const_cast<void*>(addr), len);
#else
    return mlock(addr, len) == 0;
#endif
}

bool MemoryPageLocker::Unlock(const void *addr, size_t len)
{
#ifdef WIN32
    return VirtualUnlock(const_cast<void*>(addr), len);
#else
    return munlock(addr, len) == 0;
#endif
}

LockedPageManager::LockedPageManager() : LockedPageManagerBase<MemoryPageLocker>(GetSystemPageSize())
{
	
}
