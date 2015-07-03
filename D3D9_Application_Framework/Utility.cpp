#include "stdafx.h"

	template<class Vertex>
bool CreateFillBufferFVF(LPDIRECT3DDEVICE9 pD3dDev, LPDIRECT3DVERTEXBUFFER9 Buff_output, int count, Vertex* V, int FvF_Flags)
	{
	if( FAILED(pD3dDev->CreateVertexBuffer( count*sizeof(Vertex), D3DUSAGE_WRITEONLY, FvF_Flags,
	D3DPOOL_DEFAULT, &Buff_output, NULL)) )
		return false;

	LPVOID Data;
	if( FAILED(Buff_output->Lock(0, count*sizeof(Vertex), &Data, NULL)) )
		return false;

	memcpy(Data, V, count*sizeof(Vertex));

	if( FAILED(Buff_output->Unlock()) )
		return false;

	return true;
	}

	template<class Vertex>
bool FillBufferFVF(LPDIRECT3DVERTEXBUFFER9 Buff_output, int count, Vertex* V)
	{
	LPVOID Data;
	if( FAILED(Buff_output->Lock(0, count*sizeof(Vertex), &Data, NULL)) )
		return false;

	memcpy(Data, V, count*sizeof(Vertex));

	if( FAILED(Buff_output->Unlock()) )
		return false;

	return true;
	}