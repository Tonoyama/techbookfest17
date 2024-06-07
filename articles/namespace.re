= 名前空間の実装

名前空間は、Linuxカーネルの機能の一つであり、プロセスグループを分離して独立した環境を提供します。プロセスが他のプロセスの影響を受けずに動作できるようになります。名前空間はコンテナ技術の基礎となっており、以下のような種類があります：

PID名前空間：プロセスIDを独立させる
Mount名前空間：ファイルシステムのマウントポイントを独立させる
Network名前空間：ネットワークインターフェースやネットワーク設定を独立させる
UTS名前空間：ホスト名とドメイン名を独立させる
IPC名前空間：プロセス間通信（IPC）リソースを独立させる
User名前空間：ユーザーとグループIDを独立させる
Cgroup名前空間：コントロールグループを独立させる
以下では、Go言語を使用して各名前空間を作成する方法について詳しく説明します。


== PID名前空間の作成

PID 名前空間を作成するためには、syscall.CLONE_NEWPID フラグを使用します。外部のプロセスIDと内部のプロセスIDが分離されます。

== Mount名前空間の作成

Mount 名前空間を作成するには、syscall.CLONE_NEWNS フラグを使用します。Mount名前空間を使用すると、プロセスが独自のファイルシステムビューを持つことができます。ファイルシステムのマウントポイントが隔離され、異なるプロセス間で干渉を防ぎます。

== Network名前空間の作成

syscall.CLONE_NEWNET フラグを使用します。プロセスが独自のネットワークスタックを持つことができます。ネットワークインターフェース、ルーティングテーブル、iptables設定などが独立し、プロセス間でネットワークの干渉を防ぎます。

== UTS名前空間の作成


UTS 名前空間を作成するには、syscall.CLONE_NEWUTS フラグを使用します。プロセスが独自のホスト名とドメイン名を持つことができます。システムの識別情報が分離され、プロセス間での干渉を防ぎます。

//listnum[sample][サンプル][namespace.go]{
package main

import (
    "fmt"
    "os"
    "os/exec"
    "syscall"
)

func main() {
    cmd := exec.Command("/bin/bash")

    // 名前空間のフラグを設定
    cmd.SysProcAttr = &syscall.SysProcAttr{
        Cloneflags: syscall.CLONE_NEWPID |
                    syscall.CLONE_NEWNS  |
                    syscall.CLONE_NEWNET |
                    syscall.CLONE_NEWUTS,
    }

    // 入出力を親プロセスと共有
    cmd.Stdin = os.Stdin
    cmd.Stdout = os.Stdout
    cmd.Stderr = os.Stderr

    // コマンドを実行
    if err := cmd.Run(); err != nil {
        fmt.Printf("Error: %v\n", err)
    }
}
//}

