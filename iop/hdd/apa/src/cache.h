
#ifndef _CACHE_H
#define _CACHE_H

#define CACHE_FLAG_DIRTY 0x01
typedef struct sapa_cache
{
	struct sapa_cache *next;
	struct sapa_cache *tail;
	u16 flags;
	u16 nused;
	u32 device;
	u32 sector;
	apa_header *header;
} apa_cache;

///////////////////////////////////////////////////////////////////////////////
//   Function declerations

int cacheInit(u32 size);
void cacheLink(apa_cache *clink, apa_cache *cnew);
apa_cache *cacheUnLink(apa_cache *clink);
int cacheTransfer(apa_cache *clink, int type);
void cacheFlushDirty(apa_cache *clink);
int cacheFlushAllDirty(u32 device);
apa_cache *cacheGetHeader(u32 device, u32 sector, u32 mode, int *err);
void cacheAdd(apa_cache *clink);
apa_cache *cacheGetFree();

#endif /* _CACHE_H */