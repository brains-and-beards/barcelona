module type Impl = {type navigationState; let initialScreen: navigationState;};

module Make = (Impl: Impl) => {
  type state = list(Impl.navigationState);
  type action =
    | Pop
    | Push(Impl.navigationState);
  let component = ReasonReact.reducerComponent("StatefullStackNavigator");
  module StackNavigator =
    StackNavigator.Make(
      {
        type navigationState = Impl.navigationState;
      },
    );
  let make = (~getHeaderConfig, ~render) => {
    ...component,
    initialState: () => [Impl.initialScreen],
    reducer: (action, state) =>
      switch (action) {
      | Pop =>
        switch (state) {
        | [_h, ...tail] => ReasonReact.Update(tail)
        | _ => ReasonReact.NoUpdate
        }
      | Push(screen) => ReasonReact.Update([screen, ...state])
      },
    render: ({state, reduce}) =>
      ReasonReact.element @@
      StackNavigator.make(
        ~navigationState=state,
        ~goBack=reduce((_) => Pop),
        ~getHeaderConfig,
        ~render=render(reduce(screen => Push(screen))),
      ),
  };
};
