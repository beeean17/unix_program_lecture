#include <unistd.h>
#include <stdio.h>
#include <errno.h> // for errno

int main(int argc, char *argv[])
{
    // 커맨드 라인 인수가 없는 경우 사용법 출력 후 종료
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일이름>\n", argv[0]);
        return 1;
    }

    // access() 함수의 반환값을 저장할 변수
    int can_read, can_write;

    // R_OK: 파일에 대한 읽기 권한이 있는지 확인
    // access()는 성공 시 0, 실패 시 -1을 반환합니다.
    can_read = access(argv[1], R_OK);

    // W_OK: 파일에 대한 쓰기 권한이 있는지 확인
    can_write = access(argv[1], W_OK);

    // access()가 -1을 반환한 경우, 파일이 존재하지 않는 것일 수 있습니다.
    if (can_read == -1 && errno == ENOENT) {
        printf("에러: '%s' 파일을 찾을 수 없습니다.\n", argv[1]);
        return 1;
    }

    // 권한 확인 결과에 따라 적절한 메시지 출력
    if (can_read == 0 && can_write == 0) {
        printf("'%s': 읽기/쓰기 가능 (read write)\n", argv[1]);
    }
    else if (can_read == 0) {
        printf("'%s': 읽기 전용 (read only)\n", argv[1]);
    }
    else if (can_write == 0) {
        printf("'%s': 쓰기 전용 (write only)\n", argv[1]);
    }
    else {
        printf("'%s': 읽기/쓰기 권한 없음 (no read/write permission)\n", argv[1]);
    }

    return 0;
}
