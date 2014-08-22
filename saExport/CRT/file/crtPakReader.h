#ifndef _CRTFPAKREADER_H_
#define _CRTFPAKREADER_H_


namespace Kernel
{
// Î´Íê³É


// 		struct SPAKFileHeader
// 		{
// 			fchar tag[4];
// 			fint32 offset;
// 			fint32 length;
// 		};
// 
// 		struct SPakFileEntry
// 		{
// 			string PakFileName;
// 			string simpleFileName;
// 			string path;
// 			fint32 pos;
// 			fint32 length;
// 
// 			bool operator < (const SPakFileEntry& other) const
// 			{
// 				return simpleFileName < other.simpleFileName;
// 			}
// 
// 
// 			bool operator == (const SPakFileEntry& other) const
// 			{
// 				return simpleFileName == other.simpleFileName;
// 			}
// 		};
// 
// 
// 		class CPakReader : public IUnknown
// 		{
// 		public:
// 
// 			CPakReader(IReadFile* file, bool ignoreCase, bool ignorePaths);
// 			virtual ~CPakReader();
// 
// 			//! opens a file by file name
// 			virtual IReadFile* openFile(const c8* filename);
// 
// 			//! opens a file by index
// 			IReadFile* openFile(s32 index);
// 
// 			//! returns count of files in archive
// 			s32 getFileCount();
// 
// 			//! returns data of file
// 			const SPakFileEntry* getFileInfo(s32 index) const;
// 
// 			//! returns fileindex
// 			s32 findFile(const c8* filename);
// 
// 		private:
// 
// 			//! scans for a local header, returns false if there is no more local file header.
// 			bool scanLocalHeader();
// 
// 			//! splits filename from zip file into useful filenames and paths
// 			void extractFilename(SPakFileEntry* entry);
// 
// 			//! deletes the path from a filename
// 			void deletePathFromFilename(core::stringc& filename);
// 
// 			IReadFile* File;
// 
// 			SPAKFileHeader header;
// 
// 			core::array<SPakFileEntry> FileList;
// 
// 			bool IgnoreCase;
// 			bool IgnorePaths;
// 		};

};

#endif

