
// ImagePro학번Doc.h: CImagePro학번Doc 클래스의 인터페이스
//


#pragma once


class CImagePro학번Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImagePro학번Doc() noexcept;
	DECLARE_DYNCREATE(CImagePro학번Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImagePro학번Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// 입력이미지
	unsigned char **inputImg;		// [y][x]
	unsigned char **inputImg2;		// [y][x]
	// 출력이미지
	unsigned char **resultImg;		// [y][x]

	int imageWidth;
	int imageHeight;
	int depth;		// 1=흑백,3=칼라

	int gImageWidth;		// 확대,축소를 위한 가로크기
	int gImageHeight;
	unsigned char** gResultImg;		// [y][x]

	int LoadImageFile(CArchive& ar);
	int LoadSecondImageFile(CArchive & ar);
};
