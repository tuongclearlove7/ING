
/**
 *	Include Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
		static const __m256i MATRIX4X2_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 5, 3, 1, 6, 4, 2, 0);



		/**
		 *	Method
		 */
		Matrix2x4 Matrix4x2::Transpose() const {

			return _mm256_permutevar8x32_ps(m256, MATRIX4X2_TRANSPOSE_PERMUTE);

		}

	}

}