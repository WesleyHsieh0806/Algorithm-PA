編譯:
  用make
執行程式:
  ./mps [public_cases/input file] [sampleoutputs/output file]
此程式功能:
  給定N個點 0...N-1 共有N/2條弦 算出最大不相交弦
make clean:
  刪除所有 .o 以及mps執行檔
bash checkSubmitPA2.sh B06901053_pa2.tgz:
	測試作業內容有沒有缺少 符合命名規定
tar zcvf <filename>.tgz <your directory> 壓縮


遇到的問題:killed
解決方法 find_chord那個function要用reference以避免vector浪費太多記憶體
甚麼是bash .sh?
bash .sh是一種執行shell script(.sh)的方法 用這個方法 系統會執行.sh中所有的指令