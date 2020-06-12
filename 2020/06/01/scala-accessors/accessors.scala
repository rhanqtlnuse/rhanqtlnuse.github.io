import scala.beans.BeanProperty

class VarOnly {
  var name: String = "Alan Turing"
}

class VarWithBeanProperty {
  @BeanProperty
  var name: String = "Alan Turing"
}

class VarWithPrivate {
  private var name: String = "Alan Turing"
}

// error: `BeanProperty` annotation can be applied only to non-private fields
// class VarWithPrivateAndBeanProperty {
//   @BeanProperty
//   private var name: String = "Alan Turing"
// }

class VarWithPrivateThis {
  private[this] var name: String = "Alan Turing"
}

class VarWithPrivateThisAndBeanProperty {
  @BeanProperty
  private[this] var name: String = "Alan Turing"
}

class OuterVarWithPrivateClass {
  class VarWithPrivateClass {
    private[OuterVarWithPrivateClass] var name: String = "Alan Turing"
  }
}

class OuterVarWithPrivateClassAndBeanProperty {
  class VarWithPrivateClassAndBeanProperty {
    @BeanProperty
    private[OuterVarWithPrivateClassAndBeanProperty] var name: String = "Alan Turing"
  }
}

class ValOnly {
  val name: String = "Alan Turing"
}

class ValWithBeanProperty {
  @BeanProperty
  val name: String = "Alan Turing"
}

class ValWithPrivate {
  private val name: String = "Alan Turing"
}

// error: `BeanProperty` annotation can be applied only to non-private fields
// class ValWithPrivateAndBeanProperty {
//   @BeanProperty
//   private val name: String = "Alan Turing"
// }

class ValWithPrivateThis {
  private[this] val name: String = "Alan Turing"
}

class ValWithPrivateThisAndBeanProperty {
  @BeanProperty
  private[this] val name: String = "Alan Turing"
}

class OuterValWithPrivateClass {
  class ValWithPrivateClass {
    private[OuterValWithPrivateClass] val name: String = "Alan Turing"
  }
}

class OuterMost {
  def bar(): Unit = println(new OuterValWithPrivateClassAndBeanProperty.ValWithPrivateClassAndBeanProperty().name)
  class OuterValWithPrivateClassAndBeanProperty {
    class Other {
      def foo(): Unit = println(new ValWithPrivateClassAndBeanProperty().name)
    }
    class ValWithPrivateClassAndBeanProperty {
      @BeanProperty
      private[OuterValWithPrivateClassAndBeanProperty] val name: String = "Alan Turing"
    }
  }
}
