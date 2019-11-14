package a

import (
	"github.com/p9c/sve/pkg/qt/core"

	_ "github.com/p9c/sve/pkg/qt/cmd/moc/test/sub/conf"
)

type StructSubGoA struct{}
type StructSubMocA struct{ core.QObject }
