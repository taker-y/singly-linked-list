/**
 * @file file_reader.h
 * @brief ファイル操作
 * @author taker-y
 * @date Apr 10, 2019
 */

/**
* @fn FILE *file_open(const char *filename)
* @brief ファイルを開く
* @param[in] filename 開くファイルの名前
* @return 開いたファイルへのポインタ
* @details 引数filenameの名前のファイルを開き，そのポインタを返す．
*/
FILE *file_open(const char *filename)
{
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("can't open file\n");
        exit(EXIT_FAILURE);
    }

    return fp;
}
