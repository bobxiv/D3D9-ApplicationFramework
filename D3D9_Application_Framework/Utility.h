////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////					Utility Library				  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Usuful to create the buffer and load an array of vertices into a
//Vertex Buffer quickly using FVF
//pD3dDev		The device to use
//Buff_output	The buffer to fill with the vertices
//count			The size of the array of vertices to fill
//V				The vertex array to copy into the buffer
//FvF_Flags		The FVF format of the Vertices
	template<class Vertex>
bool CreateFillBufferFVF(LPDIRECT3DDEVICE9 pD3dDev, LPDIRECT3DVERTEXBUFFER9 Buff_output, int count, Vertex* V, int FvF_Flags);

//Usuful to load an array of vertices into a Vertex Buffer quickly
//using FVF
//Buff_output	The buffer to fill with the vertices
//count			The size of the array of vertices to fill
//V				The vertex array to copy into the buffer
	template<class Vertex>
bool FillBufferFVF(LPDIRECT3DVERTEXBUFFER9 Buff_output, int count, Vertex* V);
