package c

import (
	"github.com/p9c/sve/pkg/qt/core"

	_ "github.com/p9c/sve/pkg/qt/cmd/moc/test/sub/conf"
)

type StructSubGoC struct{}
type StructSubMocC struct{ core.QObject }
