class SnakeGame {
public:

    struct Coordinate
    {
        bool operator==(const Coordinate& other) const
        {
            return X == other.X && Y == other.Y;
        }
        int X, Y;
    };

    struct Snake
    {
    public:
        Snake(Coordinate head) : _head{ head } { }
        const Coordinate Head() const { return _head; }
        const vector<Coordinate>& Body() const { return _body; }
        void Move(string direction)
        {
            _headLast = _head;

            if (direction == "U")
            {
                _head.Y -= 1;
            }
            else if (direction == "D")
            {
                _head.Y += 1;
            }
            else if (direction == "L")
            {
                _head.X -= 1;
            }
            else
            {
                _head.X += 1;
            }

            if (!_body.empty())
            {
                _body.pop_back();
                _body.insert(_body.begin(), _headLast);
            }
        }
        bool AteSelf() const
        {
            return find(_body.begin(), _body.end(), _head) != _body.end();
        }

        bool Enlarge(int bottomBound, int rightBound)
        {
            if (_body.empty())
            {
                _body.push_back(_headLast);
            }
            else
            {
                const auto& lastBodyPart = *(_body.rbegin());
                Coordinate above = { lastBodyPart.X, lastBodyPart.Y - 1 };
                Coordinate below = { lastBodyPart.X, lastBodyPart.Y + 1};
                Coordinate right = { lastBodyPart.X + 1, lastBodyPart.Y};
                Coordinate left = { lastBodyPart.X - 1, lastBodyPart.Y};

                if (find(_body.begin(), _body.end(), above) == _body.end())
                    _body.push_back(above);
                else if (find(_body.begin(), _body.end(), below) == _body.end())
                    _body.push_back(below);
                else if (find(_body.begin(), _body.end(), right) == _body.end())
                    _body.push_back(right);
                else if (find(_body.begin(), _body.end(), left) == _body.end())
                    _body.push_back(left);
                else return false;
            }

            return true;
        }
    private:



        vector<Coordinate> _body;
        Coordinate _head;
        Coordinate _headLast;
    };

    struct FoodStock
    {
    public:
        explicit FoodStock(const vector<vector<int>>& food) : _foods{food} { }
        bool HasFood() const { return _foodIndex < _foods.size(); }
        Coordinate GetFood() const
        { 
            const auto& foodStock = _foods.at(_foodIndex);
            return { foodStock[1], foodStock[0] }; 
        }
        int EatFood() { return ++_foodIndex; }
        int FoodEaten() const { return _foodIndex; }
    private:
        int _foodIndex{};
        vector<vector<int>> _foods;
    };

    SnakeGame(int width, int height, vector<vector<int>>& food) : 
        _snake{{0, 0}},
        _foodStock{food},
        _height{height},
        _width{width}
    {

    }

    bool isOutOfBounds(Coordinate coordinate) const
    {
        return coordinate.X < 0 || coordinate.X >= _width || coordinate.Y < 0 || coordinate.Y >= _height;
    }

    int move(string direction) 
    {
        _snake.Move(direction);
        
        if (_snake.AteSelf())
            return -1;

        auto snakeHead = _snake.Head();
        if (isOutOfBounds(snakeHead))
            return -1;

        if (_foodStock.HasFood())
        {
            auto food = _foodStock.GetFood();
            
            if (snakeHead == food)
            {
                if (!_snake.Enlarge(_height, _width))
                    return -1;

                return _foodStock.EatFood();
            }
        }
        return _foodStock.FoodEaten();
    }

    Snake _snake;
    FoodStock _foodStock;
    int _height, _width;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */