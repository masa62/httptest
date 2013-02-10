httptest
========

HTTPテストライブラリ

# 構成
* httptest.c
 メインファイル
 struct request_header
  基本的にHTTPのヘッダ
 char *create_request(struct request_header)
  request_headerを渡し、HTTP Request文字列を生成して返す。
  (補助関数)
 int http_test(struct request_header r, int debug)
  request_headerを渡し、HTTP_Requestを発行する。
  debugは1の時debug出力をする。
  基本的にこちらを呼び出せばよい。
* test.c
 テスト用main関数。
 $ gcc -Wall -o httptest test.c
 としたあと、
 $ ./httptest -h hostip -m METHOD
 とかすれば動く。

# 作った理由
OPTIONSメソッドが使いたかったから。

C言語の練習。
