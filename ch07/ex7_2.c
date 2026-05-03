#include "folderSize.h"

int main(void) {
    // 폴더 트리 구성 (이진 트리 구조)
    //
    //              내 컴퓨터(0MB)
    //             /              \
    //         C:\(0MB)          D:\(10MB)
    //        /      \           /      \
    // 프로그램(2MB) 자료(15MB) 음악(40MB) 그림(68MB)
    //   /       \                        /       \
    // C프로그램 Java프로그램           사진(55MB) 동영상(120MB)
    //  (200MB)   (100MB)

    folderNode *cProg   = makeFolderNode("C프로그램",   200, NULL, NULL);
    folderNode *javaProg = makeFolderNode("Java프로그램", 100, NULL, NULL);
    folderNode *program  = makeFolderNode("프로그램",      2, cProg, javaProg);
    folderNode *data     = makeFolderNode("자료",         15, NULL, NULL);
    folderNode *cDrive   = makeFolderNode("C:",           0, program, data);

    folderNode *music    = makeFolderNode("음악",         40, NULL, NULL);
    folderNode *photo    = makeFolderNode("사진",         55, NULL, NULL);
    folderNode *video    = makeFolderNode("동영상",      120, NULL, NULL);
    folderNode *picture  = makeFolderNode("그림",         68, photo, video);
    folderNode *dDrive   = makeFolderNode("D:",          10, music, picture);

    folderNode *myPC     = makeFolderNode("내 컴퓨터",    0, cDrive, dDrive);

    printf("=== 폴더 용량 계산 (후위 순회) ===\n");
    int total = getFolderSize(myPC);
    printf("----------------------------------\n");
    printf("내 컴퓨터 전체 용량: %dMB\n", total);

    return 0;
}
