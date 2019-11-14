package main

import (
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"strings"

	"github.com/therecipe/qt/utils"
)

func main() {
	target := runtime.GOOS
	path, err := os.Getwd()
	if err != nil {
		utils.Log.WithError(err).Debug("failed to get cwd")
	}
	if target == "desktop" {
		target = runtime.GOOS
	}
	if !filepath.IsAbs(path) {
		oPath := path
		path, err = filepath.Abs(path)
		if err != nil || !utils.ExistsDir(path) {
			utils.Log.WithError(err).WithField("path", path).Debug("can't resolve absolute path")
			dirFunc := func() (string, error) {
				out, err := utils.RunCmdOptionalError(utils.GoList("{{.Dir}}", oPath, "-find"), "get pkg dir")
				return strings.TrimSpace(out), err
			}
			if dir, err := dirFunc(); err != nil || len(dir) == 0 {
				utils.RunCmd(exec.Command("go", "get", "-d", "-v", oPath), "go get pkg")
				path, _ = dirFunc()
			} else {
				path = dir
			}
		}
	}
}
