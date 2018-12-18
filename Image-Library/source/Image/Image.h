#include <fstream>
#include<iostream>
#include<stdint.h>
#include<cstring>

namespace Image {

	uint32_t endian_swap (uint32_t data);

	//color types
	class  chunk {
	public:
		virtual int compare(chunk*) = 0;
	};

	typedef class  chunkG_8:public chunk{
	public: 
		uint8_t g; 
		int compare(chunk*);
		chunkG_8(uint8_t a);
		chunkG_8();
	}  chunkG_1, chunkG_2, chunkG_4;
	
	class  chunkG_16:chunk{
	public: 
		uint16_t g; 
		int compare(chunk*);
		chunkG_16(uint16_t a );
		chunkG_16();
	} ;

	typedef class  chunkI_1:public chunk {
	public: 
		uint8_t i; 
		int compare(chunk*);
		chunkI_1(uint8_t a = 0);
	}  chunkI_2, chunkI_4, chunkI_8;

	class  chunkGA_8:public chunk{
	public: 
		uint8_t g, a; 
		int compare(chunk*);
		chunkGA_8();
		chunkGA_8(uint8_t g, uint8_t a);
	};

	class  chunkGA_16:public chunk{
	public: 
		uint16_t g, a; 
		int compare(chunk*);
		chunkGA_16();
		chunkGA_16(uint16_t g, uint16_t a);
	} ;

	class  chunkRGB_8 :public chunk{
	public: 
		uint8_t r,g,b; 
		int compare(chunk*);
		chunkRGB_8();
		chunkRGB_8(uint8_t, uint8_t, uint8_t);
	} ;

	class  chunkRGB_16 :public chunk{
	public: 
		uint16_t r, g, b; 
		int compare(chunk*);
		chunkRGB_16();
		chunkRGB_16(uint16_t, uint16_t, uint16_t);
	};

	class  chunkRGBA_8 :public chunk{
	public: 
		uint8_t r, g, b, a; 
		int compare(chunk*);
		chunkRGBA_8();
		chunkRGBA_8(uint8_t, uint8_t, uint8_t, uint8_t);
	} ;

	class  chunkRGBA_16 :public chunk{
	public: 
		uint16_t r, g, b, a; 
		int compare(chunk*);
		chunkRGBA_16();
		chunkRGBA_16(uint16_t, uint16_t, uint16_t, uint16_t);
	} ;

	namespace PNG {
		using namespace std;

		typedef char byte;

		//returned by most of the functions
		enum RESULT_TYPE {
			FAIL = 0,
			CHUNKRGB_8 = 24,
			CHUNKRGB_16 = 48,
			CHUNKG_8 = 8,
			CHUNKG_16 = 16,
			SUCCESS
		};

		class point {
		public:
			int x, y;
			point();
			point(int, int);
		};


		//RESULT class
		class  RESULT {
		public:
			RESULT_TYPE type;
			const char *error;
			void *dataptr;

			RESULT(RESULT_TYPE, void*);
			RESULT(const char *);
			template <typename T>
				T data();
			operator bool();
		};
		///template defns
		template <typename T>
			T RESULT::data()
			{
				T* p = (T*)dataptr;
				return *p;
			}
		
		//handler
		class  HANDLE {
		private:
			fstream *file;
			bool fileVerified;
			bool headerAvailable;
			unsigned long chunkOffset;
			struct {
				uint32_t width;
				uint32_t height;
				byte bitDepth;
				byte colorType;
				byte compressionMethod;
				byte filterMethod;
				byte interlaceMethod;
			} header;
			void *dataChunk;

		public:
			HANDLE(const char *filename);
			~HANDLE();

			bool isVerified();

			RESULT readHeader();
			uint32_t width(); 
			uint32_t height();
			uint16_t compressionMethod();
			uint16_t bitDepth();
			uint16_t colorType();
			uint16_t filterMethod();
			uint16_t interlaceMethod();
			RESULT loadData();
			RESULT saveData(const char* );
			template <typename T>
				T* data();
		};

		template <typename T>
			T* HANDLE::data()
			{
				return (T*)dataChunk;
			}
	}
};
