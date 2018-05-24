open BsReactNative;

type screen =
  | Recommendations
  | RecommendationDetails(int);

module StatefullStackNavigator =
  StatefullStackNavigator.Make(
    {
      type navigationState = screen;
      let initialScreen = Recommendations;
    },
  );

type action =
  | Increment
  | Decrement;

type state = {
  navigationState: list(screen),
  count: int,
};

let component = ReasonReact.reducerComponent("App");

let renderScreen = (~count, ~increment, ~decrement, push, screen) =>
  switch (screen) {
  | RecommendationDetails(a) => <RecommendationDetails />
  | Recommendations => <RecommendationList />
  };

let headerTitle = screen =>
  switch (screen) {
  | Recommendations => "Recommendation"
  | RecommendationDetails(_) => "Details"
  };

let make = _children => {
  ...component,
  initialState: () => {navigationState: [Recommendations], count: 0},
  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({...state, count: state.count + 1})
    | Decrement => ReasonReact.Update({...state, count: state.count - 1})
    },
  render: ({state, reduce}) =>
    ReasonReact.element @@
    StatefullStackNavigator.make(
      ~getHeaderConfig=headerTitle,
      ~render=
        renderScreen(
          ~count=state.count,
          ~increment=reduce((_) => Increment),
          ~decrement=reduce((_) => Decrement),
        ),
    ),
};

let root =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));